#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

string get_cipher(string plaintext, string key);


int main(int argc, string argv[])
{


    //if it is 2 args and 26 chars
    if((argc == 2) && (strlen(argv[1]) == 26))
    {
        //........................if it is OK


        string key = argv[1];
        string plaintext = get_string("plaintext: ");


        //function for cipher_text
        printf("ciphertext: %s\n", get_cipher(plaintext, key));




    }

    //if args is less than 2
    else if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
}


//function for getting cipher.
string get_cipher(string plaintext, string key)
{
    int length = strlen(plaintext);
    char temp_cipher[length];
    printf("%s\n",plaintext);

    for (int i = 0; i < length; i++)
    {
        //checking if text is alphabetical
        if(isalpha(plaintext[i]))
        {
            //working with ASCII. for that creating int variable.
            int temp_char = (int)plaintext[i];
            //checking if it is capital letter and if not. in our string letters are staying in order like alphabetical, so we calling just indexes.
            if(temp_char < 91)
            {
                temp_cipher[i] = toupper(key[temp_char - 65]);
            }
            else
            {
                temp_cipher[i] = tolower(key[temp_char - 97]);
            }
        }
        else
        {
            temp_cipher[i] = plaintext[i];
        }
    }
    string total = temp_cipher;
    return total;
}
