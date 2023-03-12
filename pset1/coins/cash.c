#include <cs50.h>
#include <stdio.h>
#include <math.h>

float get_positive_float(void);

int main(void)
{
    float coin = get_positive_float();
    //Quantidade de moedas
    int qtd_moedas = 0;
    
    //Quantidade de moedas
    int qtd_moedas_25 = 0;
    int qtd_moedas_10 = 0;
    int qtd_moedas_5 = 0;
    int qtd_moedas_1 = 0;
    
    coin = round(coin * 100);
    
    while (coin >= 25)
    {
        coin -= 25;
        qtd_moedas++;
        qtd_moedas_25++;
    }
    
    while (coin >= 10)
    {
        coin -= 10;
        qtd_moedas++;
        qtd_moedas_10++;
    }
    while (coin >= 5)
    {
        coin -= 5;
        qtd_moedas++;
        qtd_moedas_5++;
    }
    while (coin >= 1)
    {
        coin -= 1;
        qtd_moedas++;
        qtd_moedas_1++;
    }
    printf("Total de moedas: %i", qtd_moedas);  
    printf("\n");
    printf("Total de moedas de 25 centavos: %i", qtd_moedas_25);  
    printf("\n");
    printf("Total de moedas de 10 centavos: %i", qtd_moedas_10);  
    printf("\n");
    printf("Total de moedas de 5 centavos: %i", qtd_moedas_5);  
    printf("\n");
    printf("Total de moedas de 1 centavo: %i", qtd_moedas_1);  
    printf("\n");
}



float get_positive_float(void){
    float n = 0;
    do
    {
        n = get_float("Qual o troco?(em centavos)\n");
    }
    while(n < 0);
    return(n);
}