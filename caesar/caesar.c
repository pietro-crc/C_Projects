#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{


    if (argc !=2)
    {
        printf("Usage: ./caesar key");
        return 1;
    }
    string sentence = get_string("plaintext: ");
    ///char converted[500] ="ciphertext: ";
    int argc1 = atoi(argv[1]);


    printf("ciphertext: ");
    for(int a= 0;a<strlen(sentence);a++)
    {

        if (sentence[a] == ' ')
        {
            printf(" ");
        }
        else
        {
            if (isupper(sentence[a]))
            {
                char lettera = sentence[a];
                int scambiato = ((sentence[a]- 65 + argc1) % 26 + 65);
                char parola = (char)scambiato;

                printf("%c", scambiato);
            }
            else if (islower(sentence[a]))
            {
                char lettera = sentence[a];
                int scambiato = ((sentence[a] - 97 + argc1) % 26 + 97);
                char parola = (char)scambiato;

                printf("%c", scambiato);
            }
            else
            {
                printf("%c",sentence[a]);
            }

        }



    }


    printf("\n");



}


