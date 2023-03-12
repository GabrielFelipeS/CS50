#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int letters = 0, words = 1, sentences = 0;
    string text = get_string("Text: ");
    for (int i = 0 ; text[i] != '\0'; i++)
    {
        if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z'))
        {
            letters++ ;
        }
        else if (text[i] == ' ')
        {
            words++ ;
        }
        else if (text[i] == '?' || text[i] == '!' || text[i] == '.')
        {
            sentences++ ; 
        }
     
    }
    
    float L = letters / (float) words * 100;
    float S = sentences / (float) words * 100;
    int index = round((0.0588 * L) - (0.296 * S) - 15.8);
    
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    
    else
    {
        printf("Grade %i\n", index);
    }
    
}