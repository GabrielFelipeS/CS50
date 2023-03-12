#include "helpers.h"

#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            int media = round( (image[h][w].rgbtBlue + image[h][w].rgbtGreen + image[h][w].rgbtRed) / 3.0 );

            image[h][w].rgbtBlue = media;
            image[h][w].rgbtGreen = media;
            image[h][w].rgbtRed = media;
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
        for (int w = 0; w < end ; w++)
        {
            RGBTRIPLE temporary = image[h][w];

            image[h][w] = image[h][end];
            image[h][end] = temporary;

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
        for (int j = 0; j < width ; j++)
        {
            copy[i][j] = image[i][j] ;
        }
    }


    for (int h = 0;h < height; h++)
    {
        for (int w = 0;w < width; w++)
        {
            int redsum , greensum, bluesum;
            float count;

            redsum = greensum = bluesum = count = 0;
            for (int i = -1 ; i < 2; i++)
            {
                for (int j = -1 ;j < 2; j++)
                {
                    if ( h + i < 0 || h + i >= height)
                    {
                        continue;
                    }
                    if ( w + j < 0 || w + j >= width)
                    {
                        continue;
                    }

                        redsum  += copy[i + h][ j + w].rgbtRed;
                        bluesum  += copy[i + h][j + w].rgbtBlue;
                        greensum += copy[i + h][j + w].rgbtGreen;
                        count++;

                }
            }
            image[h][w].rgbtRed     = round(redsum/count);
            image[h][w].rgbtGreen   = round(greensum/count);
            image[h][w].rgbtBlue    = round(bluesum/count);

        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    int gx[3][3] = { {-1, 0 , 1 }, {-2 , 0 , 2 }, {-1 , 0 , 1}};
    int gy[3][3] = { {-1 ,-2 ,-1} ,{0 ,0 ,0 },{1 ,2 ,1}};

   // printf("%i %i %i %i %i %i %i %i %i \n", gy[0][0], gy[0][1], gy[0][2], gy[1][0], gy[1][1], gy[1][2], gy[2][0], gy[2][1], gy[2][2]);
   // printf("%i %i %i %i %i %i %i %i %i \n", gx[0][0], gx[0][1], gx[0][2], gx[1][0], gx[1][1], gx[1][2], gx[2][0], gx[2][1], gx[2][2]);



    for (int h = 0 ;h < height ; h++)
    {
        for ( int w = 0; w < width; w++)
        {
            int gy_red, gy_green,gy_blue, gx_red, gx_green, gx_blue;

            gy_red = gy_green = gy_blue = gx_red = gx_green = gx_blue = 0;


                for (int i = -1; i < 2; i++)
                {
                    for (int j = -1 ; j < 2; j++)
                    {
                        int a = i + 1, c = j + 1;
                        if ( h + i < 0 || h + i > height - 1)
                        {
                            continue;
                        }

                        if ( w + j < 0 || w + j > width - 1)
                        {
                            continue;
                        }

                        gx_red += image[ h + i ][ w + j].rgbtRed * gx[i + 1][j + 1];
                        gy_red += image[h + i][ w + j].rgbtRed * gy[i + 1][j + 1];

                        gx_green += image[ h + i][ w + j].rgbtGreen * gx[i + 1][j + 1];
                        gy_green += image[ h + i][ w + j].rgbtGreen * gy[i + 1][j + 1];

                        gx_blue += image[ h + i ][ w + j].rgbtBlue * gx[i + 1][j + 1];
                        gy_blue += image[h + i][w + j].rgbtBlue * gy[i + 1][j + 1];




                    }
                }

                int red = round(sqrt( gx_red * gx_red + gy_red * gy_red)) ;
                int green = round(sqrt( gx_green * gx_green + gy_green * gy_green ));
                int blue = round(sqrt( gx_blue * gx_blue + gy_blue * gy_blue )) ;

                copy[h][w].rgbtRed = (red > 255) ? 255 : red;
                copy[h][w].rgbtGreen = (green > 255) ? 255 : green;
                copy[h][w].rgbtBlue = (blue > 255) ? 255 : blue;
        }
    }

    for (int i = 0; i < height ; i++)
    {
        for (int j = 0; j < width ; j++)
        {
            image[i][j].rgbtRed = copy[i][j].rgbtRed ;
            image[i][j].rgbtBlue = copy[i][j].rgbtBlue ;
            image[i][j].rgbtGreen = copy[i][j].rgbtGreen ;
        }
    }


    return;
}
