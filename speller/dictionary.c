// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include<stdio.h>
#include <stdlib.h>
#include "dictionary.h"
#include <string.h>
#include <strings.h>
// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;
unsigned int count =0;
// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    bool found = false;
    int index = (tolower(word[0]) -'a');
    node *current = table[index];
    while (current != NULL)
    {
        if (strcasecmp(current->word, word) == 0)
        {
            found = true;


        }
        current = current->next;
    }

    return found;

}

// Hashes word to a number
unsigned int hash(const char *word)
{

    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false

bool load(const char *dictionary)
{

    FILE *file = NULL;
    file =fopen(dictionary,"r");
    if (file == NULL)
    {
        printf("unable to open %s \n",dictionary);
        return false;
    }
    char word[LENGTH+1];
    while (fscanf(file,"%s",word) != EOF)
    {
        int index = (tolower(word[0]) -'a');
        node *n = malloc(sizeof(node));
        if (n== NULL)
        {
            fclose(file);
            free(n);
            return false;
            break;

        }
        strcpy(n-> word , word);
        n->next = NULL;

        n->next = table[index];
        table[index] = n;
        count ++;


    }

    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if (count>0)
    {
        return count;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i =0 ; i<N; i++)
    {
        node *current = table[i];
        while(current != NULL)
        {
            node *temp= current;
            current = current->next;
            free(temp);
        }

    }
    return true;



    // TODO

}
