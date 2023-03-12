#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main (int argc, string argv[])
{
    //Validação da chave
    //mais de dois argumentos
    if (argc != 2)
    {
        printf("Uso: ./ chave de substituição\n ");
        return 1;
    }
    // Se foi inserido 26 letras 
    if (strlen(argv[1]) != 26)
    {
        printf("Uso: ./ chave de substituição\n ");
        return 1;
    }
    //Se possui numeros
    for (int v = 0;argv[1][v] != '\0'; v++)
    {
        if(isdigit(argv[1][v]))
        {
            printf("Usage: ./caesar key\n ");
            return 1;
        }
    }
    //Se existe repetição
    for (int contador = 0;argv[1][contador] != '\0';contador++)
    {
        for(int contador2 = contador + 1;argv[1][contador2] != '\0';contador2++)
        {
            if(argv[1][contador] == argv[1][contador2])
            {
                printf("Usage: ./caesar key\n ");
                return 1;
            }
        }
    }
        

    string text = get_string("Text simple: ");printf("\n");
    printf("ciphertext:");
    
    for(int i = 0;text[i] != '\0'; i++)
    {
        for(int cont2 = 0 ;argv[1][cont2] != '\0';cont2++ )
        {
            if(isupper(text[i]))
            {
                if(text[i] == 'A' + cont2)
                {
                    text[i] = toupper(argv[1][cont2]);
                    break;
                }
            }
            else if(islower(text[i]))
            {
                if(text[i] == 'a' + cont2)
                {
                    text[i] = tolower(argv[1][cont2]);
                    break;
                }
            }
        }
        printf("%c", text[i]);
    }
    printf("\n");
}

