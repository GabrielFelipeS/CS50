#include <cs50.h>
#include <stdio.h>

int *numero_para_array(int ptr[], long numero);
int array_to_hash_cartao(int ptr[]);
char *calcular_string_retorno(int ptr[]);

int main(void)
{
    int DIGITOS[64];
    long NUMERO_CARTAO = get_long("> ");
    numero_para_array(DIGITOS, NUMERO_CARTAO);
    printf("%s\n", calcular_string_retorno(DIGITOS));
}

char *calcular_string_retorno(int ptr[])
{
    if (ptr[0] >= 13 && ptr[0] <= 16 && array_to_hash_cartao(ptr) == 0)
    {
        if (ptr[ptr[0]] == 4 && (ptr[0] == 13 || ptr[0] == 16))
        {
            return "VISA";
        }
        else if (ptr[ptr[0]] == 3 && (ptr[ptr[0] - 1] == 4 || ptr[ptr[0] - 1] == 7) && ptr[0] == 15)
        {
            return "AMEX";
        }
        else if (ptr[ptr[0]] == 5 && (ptr[ptr[0] - 1] == 1 || ptr[ptr[0] - 1] == 2 || ptr[ptr[0] - 1] == 3 || ptr[ptr[0] - 1] == 4 || ptr[ptr[0] - 1] == 5) && ptr[0] == 16)
        {
            return "MASTERCARD";
        }
    }
    return "INVALID";
}

int array_to_hash_cartao(int ptr[])
{
    char saltar = 'n';
    int soma = 0;
    for (int i = 1; i <= ptr[0]; i++)
    {
        if (saltar == 'n')
        {
            soma += ptr[i];
            saltar = 's';
        }
        else
        {
            int _ = ptr[i] * 2;
            if (_ < 10)
            {
                soma += _;
            }
            else
            {
                while (_ != 0)
                {
                    soma += _ % 10;
                    _ /= 10;
                }
            }
            saltar = 'n';
        }
    }
    return (soma % 10);
}

int *numero_para_array(int ptr[], long numero)
{
    int length = 0;
    for (int i = 1; numero != 0; i++)
    {
        ptr[i] = numero % 10;
        numero /= 10;
        length++;
    }
    ptr[0] = length;
    return ptr;
}