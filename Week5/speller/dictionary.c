// Implements a dictionary's functionality

#include <stdbool.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 100000;

// Hash table
node *table[N];

int dict_size = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // hash word to obtain hash value
    int hash_value = hash(word);

    //access linked list at that index in hash table
    node *n = table[hash_value];

    //traverse linked list, look for word (strcasecomp)
    while(n != NULL)
    {
        if(strcasecmp(word, n->word) == 0)
            return true;

        n = n->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // function should take a string and return an index
    // this hash function adds the ASCII values of all
    // characters in the word together
    long sum = 0;

    for(int i = 0; i < strlen(word); i++)
    {
        sum += tolower(word[i]);
    }
    return sum % N;
}



// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    //open dictionary file
    FILE *dict_point = fopen(dictionary, "r");

    //check if null
    if(dictionary == NULL)
    {
        printf("Unable to read %s\n", dictionary);
        return false;
    }

    //initialize word array
    char next_word[LENGTH + 1];

    //read strings from file one at a time
    while(fscanf(dict_point, "%s", next_word) != EOF)
    {
        //create new node for each word
        node *n = malloc(sizeof(node));
        if(n == NULL)
            return false;

        //copy word into node using strcopy
        strcpy(n->word, next_word);

        //hash word to obtain hash value
        int hash_value = hash(next_word);

        //insert node into hash table at that location
        n->next = table[hash_value];
        table[hash_value] = n;
        dict_size++;
    }

    //close file
    fclose(dict_point);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{

    return dict_size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // iterate over hash tablr and free nodes in each
    // linked list
    for(int i = 0; i < N; i ++)
    {
        //assign cursos
        node *n = table[i];

        //loop through linked list
        while(n != NULL)
        {
            //make tmp cursor
            node *tmp = n;
            //point to next
            n = n->next;
            //free tmp
            free(tmp);
        }

        if(n == NULL && i == N-1)
            return true;

    }
    return false;
}
