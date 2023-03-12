#include <stdio.h>
#include <cs50.h>
#include <string.h>
//#include <ctype.h>


int main(int argc, string argv[])
{

//    for(int i = 0; argv[i]!= 1; i++)
//        {
//            int verif = (int)isalpha(argv[1]);
//            if(verif == 0)
//            {
//               printf("Usage: ./caesar key\n ");
//                break;
//            }
            else if(argc != 2)
            {
                printf("Usage: ./caesar key\n ");
            }
            else if(verif == '1' || verif == '2')
            {
                printf("Usage: ./caesar key\n ");
            }
 //       }


    string text1 = get_string("plaintext: ");
    string codificado = text;

    printf("%s\n", codificado);
    int k = (int)argv[1];


    for(int i = 1 ;text1[i] != '\0'; i++)
    {
        codificado[i]= (text1[i] + k )%26;
    }
    printf("ciphertext: %s", codificado);
    printf("\n");


}
