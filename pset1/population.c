#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // TODO: Prompt for start size
    int get_start;
    do
    {
        get_start = get_int("Start population: ");
    } while(get_start < 9);


    // TODO: Prompt for end size
    int get_end;
    do
    {
        get_end = get_int("End population: ");
    } while (get_start > get_end);


    // TODO: Calculate number of years until we reach threshold
    int curr_population = get_start;
    int years = 0;

    while(curr_population < get_end)
    {
        curr_population = curr_population + curr_population/3 - curr_population/4;
        years++;
    }


    printf("Nr. years needed: %i\n", years);
    // TODO: Print number of years
}

//n = n + n/3 - n/4
