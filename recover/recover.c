#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    FILE *file = fopen(argv[1],"r");
    if (file == NULL)
    {
        return 1;
    }
    if (file != NULL)
    {
        BYTE buffer[512];

        int  BLOCK_SIZE =512;
        ///#define BLOCK_SIZE 512
        int numero =0;
        
        char img_jpeg[8];
        FILE *jpeg_file = NULL;
        while (fread(&buffer, 1, BLOCK_SIZE, file) == BLOCK_SIZE)
        {
            if (buffer[0]== 0xff && buffer[1]==0xd8 && buffer[2]==0xff && (buffer[3] & 0xf0)==0xe0)
            {
                printf("hello");
                sprintf(img_jpeg,"%03i.jpg",numero);
                if (numero!=0)
                {
                    fclose(jpeg_file);
                }

                jpeg_file= fopen(img_jpeg ,"w");


                numero+=1;


            }


            if (jpeg_file != NULL)
            {
                fwrite(buffer,BLOCK_SIZE,1, jpeg_file);
            }




        }
        fclose(file);
        fclose(jpeg_file);
    }




}