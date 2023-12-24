#include "helpers.h"
#include <stdio.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int a = 0; a<height;a++)
    {
        for (int b=0; b<width; b++)
        {
            int lum = ((image[a][b].rgbtBlue +image[a][b].rgbtRed +image[a][b].rgbtGreen +1)/3 );

            image[a][b].rgbtBlue = lum;
            image[a][b].rgbtRed = lum;
            image[a][b].rgbtGreen = lum;
        }
    }
}

int limit(int risultato, int min, int max)
{
  if (risultato < min)
  {
    return min;
  }
  else if (risultato > max)
  {
    return max;
  }
  else
  {
    return risultato;
  }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

        for (int a = 0; a<height;a++)
    {
        for (int b=0; b<width; b++)
        {
            int limit(int value, int min, int max);

            int sepiaRed = limit((0.393 * image[a][b].rgbtRed + 0.769 * image[a][b].rgbtGreen+ 0.189 * image[a][b].rgbtBlue+0.5),0,255);
            int sepiaGreen =limit(( 0.349 * image[a][b].rgbtRed + 0.686 * image[a][b].rgbtGreen + 0.168 * image[a][b].rgbtBlue+0.5),0,255);
            int sepiaBlue = limit((0.272 * image[a][b].rgbtRed+ 0.534 * image[a][b].rgbtGreen + 0.131 * image[a][b].rgbtBlue+0.5),0,255);

            image[a][b].rgbtBlue = sepiaBlue;
            image[a][b].rgbtRed = sepiaRed;
            image[a][b].rgbtGreen = sepiaGreen;


        }
    }


}
void swap(RGBTRIPLE a, RGBTRIPLE b)
{
    RGBTRIPLE tmp = a;
    a=b;
    b=tmp;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int len = width-1;



    for (int a = 0; a<height;a++)
    {
        int num_w =0;
        for (int b=len ; b>= width/2; b--)
        {
            RGBTRIPLE  tmp = image[a][b];
            image[a][b] = image[a][num_w];
            image[a][num_w] = tmp;


            num_w +=1;
        }

    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int BRed=0;
    int BGreen =0;
    int BBlue =0;
    for (int a = 0; a<height;a++)
    {
        for (int b=0 ; b<width; b++)
        {
            if ((b!=0 && a!=0) || (b!=height && b != width) )
            {
                BBlue = (image[a-1][b-1].rgbtBlue +image[a][b].rgbtBlue +image[a+1][b+1].rgbtBlue)/3;
                BGreen = (image[a-1][b-1].rgbtGreen+ image[a][b].rgbtGreen+ image[a+1][b+1].rgbtGreen)/3;
                BRed = (image[a-1][b-1].rgbtRed +image[a][b].rgbtRed +image[a+1][b+1].rgbtRed )/3;
            }
            else
            {
                BBlue = image[a][b].rgbtBlue;
                BGreen = image[a][b].rgbtGreen;
                BRed = image[a][b].rgbtRed;
            }
            image[a][b].rgbtBlue = BBlue;
            image[a][b].rgbtRed = BRed ;
            image[a][b].rgbtGreen = BGreen;
        }
    }
}
