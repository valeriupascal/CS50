#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //Loop through rows
    for(int i = 0; i < height; i++)
    {
        //Loop through columns
        for(int j = 0; j < width; j++)
        {
            //GET RGTBTRIPLE values
            float red = image[i][j].rgbtRed;
            float green = image[i][j].rgbtGreen;
            float blue = image[i][j].rgbtBlue;

            //Calculate average
            int average = round((red + green + blue) / 3);

            //Set all values to average
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //loop through rows
    for(int i = 0; i < height; i++)
    {
        //loop through columns
        for(int j = 0; j < width; j++)
        {
            float red = image[i][j].rgbtRed;
            float green = image[i][j].rgbtGreen;
            float blue = image[i][j].rgbtBlue;

            //new sepia value
            int sepiaRed = round(0.393 * red + 0.769 * green + 0.189 * blue);
            if (sepiaRed > 255)
                image[i][j].rgbtRed = 255;
            else
                image[i][j].rgbtRed = sepiaRed;


            int sepiaGreen = round(0.349 * red + 0.686 * green + 0.168 * blue);
            if (sepiaGreen > 255)
                image[i][j].rgbtGreen = 255;
            else
                image[i][j].rgbtGreen = sepiaGreen;


            int sepiaBlue = round(0.272 * red + 0.534 * green + 0.131 * blue);
            if (sepiaBlue > 255)
                image[i][j].rgbtBlue = 255;
            else
                image[i][j].rgbtBlue = sepiaBlue;

        }
    }
    return;
}



// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //Loop through rows
    for(int i = 0; i < height; i++)
    {
        //Loop through columns
        for(int j = 0; j < width / 2; j++)
        {
            //Reflect pixels
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

    //Loop through rows
    for(int i = 0; i < height; i++)
    {
        //Loop through columns
        for(int j = 0; j < width; j++)
        {
            //Initialize values
            float sum_red;
            float sum_blue;
            float sum_green;
            int counter;

            sum_red = sum_blue = sum_green = counter = 0;

            //for each pixel, loop vertical and horizontal
            for(int k = -1; k < 2; k++)
            {
                for(int l = -1; l < 2; l++)
                {
                    //check if pixel is outside rows
                    if(i + k < 0 || i + k >= height)
                    {
                        continue;
                    }
                    //check if pixel is outside columns
                    if(j + l < 0 || j + l >= width)
                    {
                        continue;
                    }
                    //otherwise add to sums
                    sum_red += temp[i + k][j + l].rgbtRed;
                    sum_blue += temp[i + k][j + l].rgbtBlue;
                    sum_green += temp[i + k][j + l].rgbtGreen;
                    counter++;
                }
            }

            //Get average and blur image
            image[i][j].rgbtRed = round(sum_red / counter);
            image[i][j].rgbtGreen = round(sum_green / counter);
            image[i][j].rgbtBlue = round(sum_blue / counter);
        }
    }
    return;
}
