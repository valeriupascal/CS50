#include <cs50.h>
#include <stdio.h>

int main(void)
{
  int height;

  do
  {
      height = get_int("Introduce height: ");
  } while (height > 8 || height < 1);

  for(int i = 0; i < height; i++)
  {
    for(int j = 0; j <= i; j++)
    {
        printf("#");
    }
    printf("\n");
  }

}



