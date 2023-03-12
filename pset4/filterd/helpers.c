#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            int media = round((image[h][w].rgbtRed + image[h][w].rgbtBlue + image[h][w].rgbtGreen) / 3.0);

            image[h][w].rgbtRed   = media;
            image[h][w].rgbtGreen = media;
            image[h][w].rgbtBlue  = media;
        }
    }


    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{


    for (int h = 0; h < height; h++)
    {
        for (int w = 0 ; w < width; w++)
        {
            int sepiaRed    = round(0.393 * image[h][w].rgbtRed + 0.769 * image[h][w].rgbtGreen + 0.189 * image[h][w].rgbtBlue);
            int sepiaGreen  = round(0.349 * image[h][w].rgbtRed + 0.686 * image[h][w].rgbtGreen + 0.168 * image[h][w].rgbtBlue);
            int sepiaBlue   = round(0.272 * image[h][w].rgbtRed + 0.534 * image[h][w].rgbtGreen + 0.131 * image[h][w].rgbtBlue);

            image[h][w].rgbtRed   = sepiaRed   > 255 ? 255 : sepiaRed ;
            image[h][w].rgbtGreen = sepiaGreen > 255 ? 255 : sepiaGreen;
            image[h][w].rgbtBlue  = sepiaBlue  > 255 ? 255 : sepiaBlue;

        }
    }



    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        int end  = width - 1;
        for (int w = 0; w < end; w++)
        {
            RGBTRIPLE temp = image[h][w];
            image[h][w]    = image[h][end];
            image[h][end]  = temp;

            end--;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height ; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            float count;
            int redsum, bluesum, greensum;
            redsum = bluesum = greensum = count = 0;
            for (int i = -1; i < 2; i++)
            {
                if (h + i < 0 || h + i >= height)
                {
                    continue;
                }

                for (int j = -1; j < 2; j++)
                {
                    if (j + w < 0 || j + w >= width)
                    {
                        continue;
                    }

                    redsum   += copy[h + i][w + j].rgbtRed;
                    greensum += copy[h + i][w + j].rgbtGreen;
                    bluesum  += copy[h + i][w + j].rgbtBlue;
                    count++;

                }
            }

            image[h][w].rgbtRed   = round(redsum   / count);
            image[h][w].rgbtGreen = round(greensum / count);
            image[h][w].rgbtBlue  = round(bluesum  / count);
        }
    }

    return;
}
