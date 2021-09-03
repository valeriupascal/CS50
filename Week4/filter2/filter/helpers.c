#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //loop through rows
    for(int i = 0; i < height; i++)
    {
        //loop through columns
        for(int j = 0; j < width; j++)
        {
            //get RGBTRIPLE values
            float red = image[i][j].rgbtRed;
            float green = image[i][j].rgbtGreen;
            float blue = image[i][j].rgbtBlue;

            //calculate average

            int average = round((red + green + blue) / 3);

            //set all values to average
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //loop through rows
    for(int i = 0; i < height; i++)
    {
        //loop through columns
        for(int j = 0; j < width/2; j++)
        {
            //reflect pixels
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //create temp array
    RGBTRIPLE temp[height][width];
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    //loop through rows
    for(int i = 0; i < height; i++)
    {
        //loop through columns
        for (int j = 0; j < width; j++)
        {
            //initialize values
            float sum_red;
            float sum_green;
            float sum_blue;
            int counter;

            sum_red = sum_green = sum_blue = counter = 0;

            //for each pixel loop vertical and horizontal
            for (int k = -1; k < 2; k++)
            {
                for(int l = -1; l < 2; l++)
                {
                    //check if pixel is outside the rows
                    if(i + k < 0 || i + k >= height)
                        continue;

                    //check if pixel is outside the columns
                    if(j + l < 0 || j + l >= width)
                        continue;

                    //otherwise add to sums
                    sum_red += temp[i + k][j + l].rgbtRed;
                    sum_green += temp[i + k][j + l].rgbtGreen;
                    sum_blue += temp[i + k][j +l].rgbtBlue;
                    counter++;
                }
            }

            //get average blur image
            image[i][j].rgbtRed = round(sum_red / counter);
            image[i][j].rgbtGreen = round(sum_green / counter);
            image[i][j].rgbtBlue = round(sum_blue / counter);
        }
    }
    return;
}




// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    //create temp array
    RGBTRIPLE temp[height][width];
    for(int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    //Initialize Sobel arrays
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    //Loop through rows
    for(int i = 0; i < height; i++)
    {
        //loop through columns
        for(int j = 0; j < width; j++)
        {
            //Initialize ints total GX-ses
            float Gx_red;
            float Gx_blue;
            float Gx_green;
            float Gy_red;
            float Gy_blue;
            float Gy_green;

            Gx_red = Gx_blue = Gx_green = Gy_red = Gy_blue = Gy_green = 0;

            //for each pixel, loop vertical and horizontal
            for(int k = -1; k < 2; k++)
            {
                for(int l = -1; l < 2; l++)
                {
                    //check if pixels out of rows
                    if(i + k < 0 || i + k >= height)
                            continue;

                    //check if pixels out of columns
                    if(j + l < 0 || j + l >= width)
                            continue;

                    //otherwise add to sums
                Gx_red += temp[i + k][j + l].rgbtRed * Gx[k + 1][l + 1];
                Gx_blue += temp[i + k][j + l].rgbtBlue * Gx[k + 1][l + 1];
                Gx_green += temp[i + k][j + l].rgbtGreen * Gx[k + 1][l + 1];

                Gy_red += temp[i + k][j + l].rgbtRed * Gy[k + 1][l + 1];
                Gy_blue += temp[i + k][j + l].rgbtBlue * Gy[k + 1][l + 1];
                Gy_green += temp[i + k][j + l].rgbtGreen * Gy[k + 1][l + 1];
                }

            }

            //calculate Sobel operator
            int red = round(sqrt(Gx_red * Gx_red + Gy_red * Gy_red));
            int green = round(sqrt(Gx_green * Gx_green + Gy_green * Gy_green));
            int blue = round(sqrt(Gx_blue * Gx_blue + Gy_blue * Gy_blue));

            //check if 255 more
            if(red > 255)
                red = 255;
            if(green > 255)
                green = 255;
            if(blue > 255)
                blue = 255;

            //assign new values to pixels
            image[i][j].rgbtRed = red;
            image[i][j].rgbtGreen = green;
            image[i][j].rgbtBlue = blue;
        }
    }
    return;
}
