#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

#define MAX 512


int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        printf("Uso: ./recover card.raw");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if(!file)
    {
        return 1;
    }
    int jpeg_count = 0;

    FILE *img;
    BYTE buffer[MAX];
    char *name = malloc(9);
    while(fread(buffer, 1, MAX, file))
    {

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&  ((buffer[3] & 0xf0) == 0xe0))
        {
            if(jpeg_count != 0)
            {
                fclose(img);
            }

            sprintf(name , "%03i.jpg", jpeg_count);
            img = fopen(name, "w");
            fwrite(buffer, 1 , MAX, img);

            jpeg_count++;
        }

        else if (jpeg_count > 0)
        {
            fwrite(buffer, 1 , MAX, img);
        }
    }


    free(name);
    fclose(img);
    fclose(file);
}