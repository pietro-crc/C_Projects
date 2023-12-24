#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string text = get_string("Text:");


    float letter = 0;
    float words = 1;
    float sentence = 0;

    for(int i = 0; i < strlen(text); i++)
    {

        if (text[i] == ' ')
        {
            words +=1;
        }
        else if ( text[i] == '.'||text[i] == '!'||text[i] == '?')
        {
            if (text[i-1] !='.')
            {
                sentence +=1;
            }
        }
        else if (text[i] != '\'' && text[i] != ',')
        {
            letter+=1;
        }

    }

    float L = (letter/words)*100;
    float S = (sentence/words)*100;




    float result = 0.0588*L - 0.296*S -15.8;
    int result0 = round(result);
 

      if (result < 1)
        {
            printf("Before Grade 1\n");
        }
       else if (result > 16)
        {
            printf("Grade 16+\n");
        }
       else
        {
            printf("Grade %i\n", result0);
        }

}