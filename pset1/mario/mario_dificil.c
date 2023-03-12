#include <stdio.h>
#include <cs50.h>

int get_positive_int(void);

int main(void)
{
    int resp = get_positive_int();
    for (int control = resp; control > 0; control--)
    {
        int pular = control - 1;
        int esq = resp - pular;
        int dir = resp - pular;
        //piramide 1
        while (pular > 0)
        {
            printf(" ");
            pular--;
        }
        while (esq > 0)
        {
            printf("#");
            esq--;
        }
        //espaço entre elas
        
        printf(" ");
        
        //piramide 2
        while (dir > 0)
        {
            printf("#");
            dir--;
        }
        printf("\n");  
    }
       
}
    
int get_positive_int(void)
{
    int n = 0;
    do
    {
        n = get_int("Tamanho: ");
    }
    while (n < 1 || n > 8);
    return n;
}
