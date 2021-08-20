#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

string get_cipher(string plain, int argument);
int calculate_shift_value (int argument);

int main(int argc, string argv[])
{
    //counting and checking command line
    if(argc == 2)
    {
        int n = strlen(argv[1]);
        if (n > 2)
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if(argv[1][i] >= '1' && argv[1][i] <= '9')
                {
                    continue;
                }
                else
                {
                     printf("not digit\n");
                     return 1;
                }
            }
            printf("Success\n");
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }



    //converting string argument in int;
    int argument = atoi(argv[1]);
    int shift_value = calculate_shift_value(argument);


    //getting plaintext from the user and create ciphertext;
    string plain_text = get_string("plaintext: ");


    //printing result
    printf("%s\n", get_cipher(plain_text, shift_value));


}




//FUNCTIONS
//function get cipher
string get_cipher(string plain, int argument)
{
    int lenght = strlen(plain);
    char cipher_text[lenght];

    for(int i = 0; i < lenght; i++)
    {
        int temp_char_dec = (int)plain[i] + argument;
        if(isalpha(plain[i]))
        {
            if (((int)plain[i] <= 90 && temp_char_dec > 90) || ((int)plain[i] >= 90 && temp_char_dec > 122))
            {
                temp_char_dec = temp_char_dec - 26;
            }
            cipher_text[i] = temp_char_dec;
        }
        else if(plain[i] >= ' ' && plain[i] <= '/')
        {
            cipher_text[i] = plain[i];
        }
        else
        {
            printf("not alphabetical");
            break;
        }
    }
   string total = cipher_text;
   return total;
}

// Calculatin Shift value if it is greater that 26
int calculate_shift_value (int argument)
{
    int shift_value = argument % 26;
    return shift_value;
}
