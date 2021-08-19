#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);
string find_winner (int score1, int score2);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    printf("%s", find_winner(score1, score2));
}

int compute_score(string word)
{
    int n = strlen(word);
    char temp_up;
    int score = 0;

    for (int i = 0; i < n; i++)
    {
        if((word[i] >= '!' && word[i] <= '@'))
        {
            score = score + 0;
        }
        else
        {
        temp_up = toupper(word[i]);
        int point_index = temp_up - 65;
        score += POINTS[point_index];
        }
    }
    return score;
}

//function for finding winner;
string find_winner (int score1, int score2)
{
    if (score1 > score2)
    {
        return "Player 1 wins!\n";
    }
    else if (score1 < score2)
    {
        return "Player 2 wins\n";
    }
    else
    {
        return "Tie\n";
    }
}
