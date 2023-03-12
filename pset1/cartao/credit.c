#include <cs50.h>
#include <stdio.h>

int *numero_para_array(int ptr[], long numero);
int multiplica_array(int ptr[]);
char *calcula_string (int ptr[]);

int main(void)
{
    int cont = 1;
    int digitos[64];
    long card = get_long("Insira o numero do cartão: ");
    if (card < 999999999999 || card > 9999999999999999)
    {
        printf("Invalido\n");
    }
    else
    {
        numero_para_array(digitos, card);
        printf("%s\n", calcula_string(digitos));
    }
}


char *calcula_string(int ptr[])
{
    if(ptr[0] >= 13 && ptr[0] <= 16 && multiplica_array(ptr) == 0)
    {
        if(ptr[ptr[0]] == 4 && (ptr[0] == 13 || ptr[0] == 16))
        {
            return "Visa";
        }
        if(ptr[0] == 15 && ptr[ptr[0]] == 3  && (ptr[ptr[0] - 1] == 4 || ptr[ptr[0] - 1] == 7 ))
        {
            return "America Express";
        }
        if(ptr[0] == 16 && ptr[ptr[0]] == 5  && (ptr[ptr[0] - 1] == 2 || ptr[ptr[0] - 1] == 3 || ptr[ptr[0] - 1] == 4 || ptr[ptr[0] - 1] == 5))
        {
            return "Mastercard";
        }
    }
    return "invald";
}

int *numero_para_array(int ptr[], long numero)
{
    int compr = 0;
    for (int i = 1; numero != 0; i++)
    {
        ptr[i] = numero % 10;
        numero /= 10;
        printf("%i\n%ld\n", ptr[i], numero);
        compr++;
    }

    ptr[0] = compr;
    return ptr;
}

int multiplica_array(int ptr[])
{
    char pular = 'n';
    int soma = 0;
    for (int i = 1;i <= ptr[0]; i++ )
    {
        if (pular == 'n')
        {
            soma += ptr[i];
            pular = 's';
        }
        else
        {
            int mult = ptr[i] * 2;
            if(mult < 10)
            {
                soma += mult;
            }
            else
            {
                while (mult !=0)
                {
                    soma += mult % 10;
                    mult /= 10;
                }
            }
            pular = 'n';
        }
    }
    return (soma % 10);
}

