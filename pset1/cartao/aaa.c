#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
long int card =0; //declara variavel grande inteira
int i = 1; //contador



        card = get_long("\ncard number: ");// pede o numero ao usuario

    if (card < 999999999999 || card > 9999999999999999)// caso tenha menos ou mais digitos regeita o numero
    {
        printf("INVALIDO\n\n"); //caso nã cumpra as condições, escreve
    }
    else
    {
        long cc = card;
        int passo1 = 0;
        while(cc != 0) //executa sequencia até que o resultado seja 0
        {
            if ( i % 2 == 0) // para quando o resto da div. for maior que 0
            {
                int p1 = (cc % 10) * 2; 
                if (p1 > 9)
                {
                    int passo2 = p1;
                    while(passo2 != 0)
                    {
                        passo1 += passo2 % 10;
                        passo2 = passo2 / 10;
                    }
                }
                else
                {
                    passo1 += p1;
                }
            }
        else
        {
            passo1 += cc %10;
        }
        cc = cc / 10;
        i++;
        }
// loop de verificação do tipo de cartão
        int expo = (i - 3);
        long c_test = card / pow ( 10, expo );
        if ((passo1 % 10 ==0) &&(c_test == 34 && c_test ==37))
        {
            printf("\nAMEX\n\n");
        }
        else if((passo1 %10 ==0) && (c_test > 50 && c_test <56))
        {
            printf("\nMASTERCARD\n\n");
        }
        else if ((passo1 % 10 == 0) && (c_test > 39 && c_test < 50))
        {
        printf("\nVISA\n\n");
        }
        else
        {
            printf("\nINVALIDO\n\n");
        }
    }

} 
