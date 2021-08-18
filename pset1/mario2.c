#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;

    do
    {
        height = get_int("height: ");
    } while (height > 8 || height < 0);


    for (int i=0; i < height; i++)
    {
        for (int j=0; j < height; j++)
        {
            if (i + j < height - 1)
            printf(" ");

            else
            printf("#");
        }
        printf("  ");
        for (int k =0; k <= i; k++)
        {
            printf("#");
        }
        printf("\n");
    }


}
