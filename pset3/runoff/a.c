#include <cs50.h>
#include <string.h>
#include <stdio.h>

//Estrutura
typedef struct
{
    string name;
    int votes;
}
candidate;


//Funções
int vote(string candidatos[]);



//Variaveis globais
string name;
int candidate_count ;
int rank;
int voter;



//Funções
int erro(int argc);
int vote ( int voter, int rank, string name);



int main (int argc, string argv[])
{
     rank = argc - 1;
     
    //Impedir que tenha um ou menos itens
    if(erro(argc) == 1)
    {
        return 1;
    }

    //Numeros de votos, não aceitar menos do que 1
    do
    {
        voter = get_int("Número de eleitores: ");
    }
    while(voter <= 0);

int vote ( int voter, int rank, string name);
}



int vote (int voter, int rank, string name)
{
    printf("Vou surtar ");
}


int erro(int argc)
{
    if(argc <= 1)
    {
        printf("ERRO!\n");
        return 1;
    }
    return 0;
}





for(int i = 0 ; i < voter_count; i++)
    {
        for(int j = 0; j < candidate_count; j++)
        {
            if(preferences[i][0] == j && candidates[i].eliminated == false)
            {
                candidates[j].votes++;
                break;
            }
            else if(preferences[i][0] == j && candidates[i].eliminated == true)
            {
                for(int p = 0; p < voter_count; p++)
                {
                    for(int a = 0; a < candidate_count; a++ )
                    {
                        if(preferences[i][p + 1] == a && candidates[i].eliminated == false)
                        {
                            candidates[a].votes++;
                            break;
                        }
                    }
                }
            }
        }
    }