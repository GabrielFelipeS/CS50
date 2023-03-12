#include <math.h>
#include <cs50.h>
#include <stdio.h>


int main(void)
{
    int inicial;
    int final;
    int anos = 0;
    do
    {
        inicial = get_int ("Tamanho inicial: ");
    } while ( inicial < 9);
    
    do 
    {
        final = get_int (" Tamnho final: ");
    } while ( final < 9 || inicial > final );
    
    while (inicial < final)
    {
        inicial = inicial + (inicial / 3) - (inicial / 4);
        anos++;
    }
    
        printf("Years: %i", anos);
        
    
}



