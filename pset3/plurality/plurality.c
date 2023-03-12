#import <cs50.h>
#import <string.h>
#include <stdio.h>

//Estrutura
typedef struct
{
    string name;
    int votes;
}
candidate;

//Maximo de candidatos
#define MAX 9
candidate candidates[MAX];

//Variaveis Globais
int candidate_count;
int numbers_voters;

//Funções
bool vote(string name_voted);
void print_winner(void);

int main(int argc, string nomes_inseridos[])
{
    //Variaveis
    
    
    //Retira o './plurality' da contagem.
    candidate_count = argc - 1; 

    //Transfere o argv para o candidates.name
    for (int u = 0; u <= candidate_count; u++)
    {
        candidates[u].name = nomes_inseridos[u + 1];
    }

    //Quantidade de votantes
    do
    {
        numbers_voters = get_int("Numbers of voters: ");
    }
    while (numbers_voters <= 0);

    //Soma de votos
    for (int i = 0; i < numbers_voters; i++)
    {
        string name_voted = get_string("Vote: ");
        //1º Função após o main
        if (!vote(name_voted))
        {
            printf("Invalid vote\n");
        }
    }
    
    //2º Função após o main
    print_winner();
}

bool vote(string name_voted)
{
    
    for (int i = 0; i < candidate_count ; i++)
    {
        if (strcmp(name_voted, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

void print_winner(void)
{
    int winner = 0;
    
    //Ver o mais votado
    for (int i = 0; i < candidate_count ; i++)
    {
        if (candidates[i].votes > winner)
        {
            winner = candidates[i].votes;
        }
    }
    
    //Printar o(s) mais votado
    for (int u = 0; u < candidate_count ; u++)
    {
        if (candidates[u].votes == winner)
        {
            printf("%s\n", candidates[u].name);
        }
    }
}