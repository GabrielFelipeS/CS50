#include "helpers.h"

#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            int media = round((image[h][w].rgbtRed + image[h][w].rgbtGreen + image[h][w].rgbtBlue) / 3.0);
            image[h][w].rgbtRed   = media;
            image[h][w].rgbtGreen = media;
            image[h][w].rgbtBlue  = media;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        int end = width - 1;
        for (int w = 0; w < end; w++)
        {
            RGBTRIPLE temp = image[h][w];
            image[h][w] = image[h][end];
            image[h][end] = temp;
            end--;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            copy[h][w] = image[h][w];
        }
    }

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            int redsum, greensum,bluesum;
            float count;
            redsum = greensum = bluesum = count = 0;

            for (int i = -1; i < 2; i++)
            {
                if ( i + h < 0 || i + h >= height)
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

                image[h][w].rgbtRed   = round(redsum / count);
                image[h][w].rgbtGreen = round(greensum / count);
                image[h][w].rgbtBlue  = round(bluesum / count);

        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1 , 0, 1}};
    int gy[3][3] = {{-1, -2, -1}, {0, 0 ,0}, {1, 2, 1}};


    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
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
            int gx_red, gy_red, gx_blue, gy_blue, gx_green, gy_green;
                gx_red = gy_red = gx_blue = gy_blue = gx_green = gy_green = 0;

            for (int i = -1; i < 2; i++)
            {
                for (int j = -1; j < 2; j++)
                {
                    if (h + i < 0 || h + i >= height)
                    {
                        continue;
                    }

                    if (w + j < 0 || w + j >= width)
                    {
                        continue;
                    }

                    gx_red += copy[h + i][w + j].rgbtRed * gx[i + 1][j + 1];
                    gy_red += copy[h + i][w + j].rgbtRed * gy[i + 1][j + 1];

                    gx_green += copy[h + i][w + j].rgbtGreen * gx[i + 1][j + 1];
                    gy_green += copy[h + i][w + j].rgbtGreen * gy[i + 1][j + 1];

                    gx_blue += copy[h + i][w + j].rgbtBlue * gx[i + 1][j + 1];
                    gy_blue += copy[h + i][w + j].rgbtBlue * gy[i + 1][j + 1];
                }
            }

            int red   = round(sqrt( pow(gx_red, 2)   + pow(gy_red, 2)));
            int green = round(sqrt( pow(gx_green, 2) + pow(gy_green, 2)));
            int blue  = round(sqrt( pow(gx_blue, 2)  + pow(gy_blue, 2)));

            image[h][w].rgbtRed   = red   > 255? 255 : red;
            image[h][w].rgbtGreen = green > 255? 255 : green;
            image[h][w].rgbtBlue  = blue  > 255? 255 : blue;

        }
    }
    return;
}
