#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing

    for ( int a =0; a<height ; a++)
    {
        for ( int b =0; b< width; b++)
        {
            if(image[a][b].rgbtGreen == 0 && image[a][b].rgbtBlue == 0 &&image[a][b].rgbtRed == 0 )
            {
                image[a][b].rgbtRed = 200;
                image[a][b].rgbtGreen = 100;
                image[a][b].rgbtBlue = 255;

            }
        }
    }
}
