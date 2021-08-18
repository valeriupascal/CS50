#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //Get number of card
    long n = get_long("Number: ");

    //check if it is valid
    int i = 0;
    long cc = n;
    while(cc > 0)
    {
        cc = cc / 10;
        i++;
    }

    if (i != 13 && i != 15 && i !=16)
    {
        printf("INVALID NUMBER\n");
        return 0;
    }

    //Remove last digit and add to sum
    int sum1 = 0;
    int sum2 = 0;
    long x = n;
    int mod1;
    int mod2;
    int d1;
    int d2;
    int total = 0;

    do
    {
        mod1 = x % 10;
        x = x / 10;
        sum1 = sum1 + mod1;

        //Remove second last digit
        mod2 = x % 10;
        x = x / 10;

        //dublam mod 2 si adaugam la sum
        mod2 = mod2 * 2;
        d1 = mod2 % 10;
        d2 = mod2 / 10;
        sum2 = sum2 + d1 + d2;

    } while (x > 0);

    total = sum1 + sum2;



    //checck result with Luhn algorithm
    if (total % 10 != 0){
        printf("INVALID CARD");
        return 0;
    }

    //check first 2 digits
    long start = n;
    do
    {
        start = start / 10;
    }while (start > 100);


    //check what type of card
    if((start / 10 == 5) && (0 < start % 10 && start % 10 < 6))
    {
        printf("MASTERCARD \n");
    }
    else if ((start / 10 == 3) && (start % 10 == 4 || start % 10 == 7))
    {
        printf("American Express \n");
    }
    else if (start / 10 == 4)
    {
        printf("VISA \n");
    }
    else
    {
        printf("INVALID CARD \n");
    }
}
