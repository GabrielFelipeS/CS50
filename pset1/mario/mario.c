#include <stdio.h>
#include <cs50.h>

int get_positive_int(void);

int main(void)
{
    int resp = get_positive_int();
    for (int control = resp; control > 0; control--)
    {
        int Esp = control - 1;
        int alt = resp - Esp;
        
        
        while (Esp > 0)
        {
            printf(" ");
            Esp--;
        }
        while (alt > 0)
        {
            printf("#");
            alt--;
        }
    

    }
       
}
    
int get_positive_int(void)
{
    int tamanho = 0;
    do
    {
        tamanho = get_int("Tamanho: ");
    }
    while (tamanho < 1 || tamanho > 8 );
    return tamanho;
}