#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int count_index(int letter, int word, int sentence);



int main(void)
{
  //getting input from the user
    string user_text = get_string("Put text here: ");

    int letters = count_letters(user_text);
    int words = count_words(user_text);
    int sentences = count_sentences(user_text);

    int count_indexes = count_index(letters, words, sentences);

    printf("Nr. of letters: %i\nNr. of words: %i\nNr. of sentences: %i\n", letters, words, sentences);

  //checking result of formula.
    if (count_indexes <= 0)
    {
        printf("Before Grade 1\n");
    }
    else if(count_indexes >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade: %i\n", count_indexes);
    }
}


//counting letters
int count_letters(string text)
{
    char temp_letter;
    int total_letters = 0;

    for(int i = 0, n = strlen(text); i < n; i++)
    {
        temp_letter = toupper(text[i]);
        if(temp_letter >= 'A' && temp_letter <= 'Z')
        {
            total_letters++;
        }
    }
    return total_letters;
}

//counting words
int count_words(string text)
{
    int total_words = 0;

    for(int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ')
        {
            total_words++;
        }
    }
    return total_words + 1;
}

//counting sentences
int count_sentences(string text)
{
    int total_sentences = 0;

    for(int i = 0, n = strlen(text); i < n; i++)
    {
        if(text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            total_sentences++;
        }
    }
    return total_sentences;
}

//counting with COLEMAN_LIAU FORMULA
int count_index (int letter, int word, int sentence)
{
    //calculate average number of letters per 100 words in the text
    float av_letters = letter / (float)word * 100;

     //calculate average number of sentences per 100 words in the text
    float av_sentences = sentence / (float)word * 100;

    //calculate with Coleman-Liau formula
    int formula = round(0.0588 * av_letters - 0.296 * av_sentences - 15.8);


    return formula;
}

