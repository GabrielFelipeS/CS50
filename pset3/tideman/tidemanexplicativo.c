#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }
        record_preferences(ranks);
        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)//Comapra o nome dado pelo eleitor e dos candidatos
        {
            ranks[rank] = i;//Adiciona no ranks[rank] a escolha, o rank é a preferencia do eleitor
            return true;    //Já o ranks é o ranks[rank] e a organização de todas as preferencias
        }                   //ranks[0] = i sendo i o candidado ao qual o eleitor escolheu
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {                                       //É como se fossee uma tabela,
            preferences[ranks[i]][ranks[j]]++;  //        |  alice  |  Bob  |Charlie|
        }                                       //Alice   |         |       |       |
    }                                           //Bob     |         |       |       |
    return;                                     //Chalie  |         |       |       |
}                                               //Cada ranks[i] representa o rank do colocado 1º ranks[0]
                                                //Ele vence de todos os outros então por isso fica num loop
// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for (int i = 0 ; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {                                   //Preferences[i][j] leia-se preferido i em relação a j
                pairs[pair_count].winner = i;   //Verifica colocado por colocado é o inverso dele
                pairs[pair_count].loser = j;    //preferences[0][1] é maior que preferences[1][0]?
                pair_count++;                   //Se sim o preferences preferences[0][1] é o vencedor
            }                                   //Então ele pega i que é mais preferivel que j
        }                                       //E adiciona a quandidate de pares++
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    for (int i = pair_count - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (preferences[pairs[j].winner][pairs[j].loser] < preferences[pairs[j + 1].winner][pairs[j + 1].loser])
            {
                                            // Bubble sort:
                pair temporary = pairs[j];  // Ele veririfia em pares, array = [5,6,1,4,2,7] array[j] < array[j+1]
                pairs[j] = pairs[j + 1];    // 5 é menor que 6? sim então troca [6,5,1,4,2,7]
                pairs[j + 1] = temporary;   // 5 é menor que 1? não, netão continua [6,5,1,4,2,7]
            }                               // 1 é menor que 4? sim então troca [6,5,4,1,2,7]
        }                                   // 1 é menor que 2? sim, então troca  [6,5,4,2,1,7]
    }                                       // 1 é menro que 7? Sim, então troca, [6,5,4,2,7,1]
    return;                                 // Agora o codigo bloqueia o ultimo numero do arrayj
}                                           // Já que o i diminuiu em 1

bool iscyrcle(int winner, int loser)
{
    int origin = loser;
    for (int i = 0; i  < candidate_count; i++)
    {
        if (locked[i][winner])   //Se o locked[1][0] for verdadeiro
        {                        //Ele vai inverter atribuir i a winner ficando locked[1][1]
            winner = i;
            if (winner == origin)//Compara a entrada se winner que no caso é 1 for igual ao loser que no caso é 1
            {                     
                return true;     //retorna true, que vai fazer o if da função não executar
            }
            i = 0;               //Ele vai trocar i pra 0, assim ele vai passar por todos os supostamente ganham de 0
        }                        //Se algum existir ele refaz, caso contrario o for se encerra é retorna false, executando o if
    }
    return false;
}
// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int i = 0 ; i < pair_count ; i++)
    {
        int winner = pairs[i].winner;           //Nomes mais "digeriveis", pair[0].winner é o que teve a maior vitoria
        int loser = pairs[i].loser;             //Nomes mais "digeriveis", pair[0].loser é o que teve a maior derrota
        if (!locked[winner][loser])             // Se o locked[winner][loser] for verdadeiro
        {                                       //  NÃO EXECUTA, por causa do ! que inverte !true = false, !false = true
            if (!iscyrcle(winner, loser))       // o if só vai ser executado se icyrcle devolver false
            {                                   // Se executado ele "bloqueara" a seta, atribuindo ela o true
                locked[winner][loser] = true;   // Isso significa que a seta não produz um ciclo
            }
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        bool iswinner = true;                   
        for (int j = 0 ; j < pair_count; j++)
        {
            if (locked[j][i])       // Verifica varias vezes e ve que no locked[2][0] é verdadeiro, já que Charlie[2] ganhou de Alice[0] 
            {                       //Atribuindo o iswinner como false e recomeçando tudo só que com i sendo = 1
                iswinner = false;   //Com i é igual a 1 ele vai testado e acha em locked[0][1] verdadeiro, quebrando o for e começando de novo
                break;              //Já no i = 2, ele passa por todos os locked[j][2] é não acha nenhum verdadeiro
            }                       //Ou seja, não tem nenhuma ceta apontada pra 2[charlie]
        }                           //Concedendo a vitoria a charlie, obs, bob ganhou de charlie, mas como foi a menor vitoria, foi desconsiderada no 
        if (iswinner == true)       //iscyrcle já que a vitoria de charlie sobre alice veio primeiro, pois foi maior do que a de bob x charlie
        {
            printf("%s\n", candidates[i]);
        }
    }
    return;
}

