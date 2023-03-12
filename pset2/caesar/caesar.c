#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>


int main(int argc, string argv[])
{
        // Mais de dois argumentos
        if(argc != 2)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }

    // Verificação se é uma letra
    for(int i = 0; i <= strlen(argv[1]);i++)
    {
        if(isalpha(argv[1][i]))
        {
            printf("Usage: ./caesar key\n ");
            return 1;
        }

    }


        //Chave
        int key = atoi(argv[1])%26;
        // Verificação da chave
        if(key <= 0)
        {
            printf("Usage: ./caesar key\n ");
            return 1;
        }
        //voltar
        int voltar = 26 - key;

        //Pedido do Texto
        string text = get_string("plaintext: ");
        printf("ciphertext: ");

        //Converção ASCII
        int cifra;
        for(int i = 0; text[i] != '\0'; i++)
        {
            cifra = text[i];
            if(isalpha(text[i]))
            {
                if(isupper(text[i]))
                {
                    if(cifra + key > 'Z')
                    {
                        cifra -= key + voltar;
                    }
                    cifra += key;
                }

                //Verifica se é minuscula
                else if(islower(text[i]))
                {
                    if(cifra + key > 'z')
                    {
                        cifra -= key + voltar;
                    }
                    cifra += key;
                }
            }
            printf("%c", cifra);

        }
        printf("\n");
        return 0;
}