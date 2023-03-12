#include <cs50.h>

int main (int agrc, string argv[])
{
    string lista[argc - 1];
    for(int i = 0;argv[i + 1] != '\0';i++)
    {
        lista[i] = argv[i + 1]; 
    }
}