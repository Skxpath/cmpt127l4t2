#include <stdio.h> //Needed for printf.
#include <stdint.h> //Needed for uint8_t
#include <stdlib.h> //Needed for Abs()
#include <stdbool.h>

void draw_rectangle( uint8_t array[],
                     unsigned int cols,
                     unsigned int rows,
                     int x,
                     int y,
                     int rect_width,
                     int rect_height,
                     uint8_t color )
{
//Dimensions of the array based on the rectangle width and height
const int rectSize = rect_height*rect_width;

//Dimensions of the grid
//const int gridSize = cols*rows;

//Define an array just large enough to encapsulate the entire rectangle
int rectangle[rectSize];

//Define an array for the grid
//int grid[gridSize];

//Define the height and width of the rectangle
//These can be negative, so we iterate our algorithm accordingly
//Positive height and width go towards the right and down respectively, and negative the opposite
const int height = rect_height;
const int width = rect_width;

//Defines the lengths of the rectangle
//const int xLength = abs(width-x); //columns
//const int yLength = abs(height-y); //rows

//Algorithm is defined so each row is split in the array by a modulus of rows
//I.e. 3x3 rectangle needs array of size 9
//First three elements refer to the first row, second three elements refer to the second row, etc.

//If length and width are both positive
if (height > 0 && width > 0) {

//For each row...
for (int y = 0; y < height; y++) {

bool firstOrLastRow = (y == 0 || y == height-1);

int indexMultiplier = y*height;

//For each column entry of a row...
        for (int x = 0; x < width; x++) {
          
bool firstOrLastColumn = (x == 0 || x == width-1);
//Index of columns
int xIndex = x+indexMultiplier;

//If this is the first or last row..
            if (firstOrLastRow) {

              //Set everything inside the first row to the color
                rectangle[xIndex] = color;

              //If this is the first or last column entry in the row
            } else if (firstOrLastColumn) {

              rectangle[xIndex] = color;

            } else {
              //In the case when it isnt an edge of the rectangle
              rectangle[xIndex] = 0;

            }

            }

        }

    }


for (int i = 0; i < rectSize; i++) {

  if (i % width == 0) {
    printf("\n");
  }

  printf("%i ", rectangle[i]);

}

}



int main( int argc, char* argv[] )
{

printf("Hello world!\n");

uint8_t grid[15];
unsigned int cols = 5;
unsigned int rows = 5;
int x = 1;
int y = 1;
int rect_width = 3;
int rect_height = 3;
uint8_t color = 1;

draw_rectangle(grid, cols, rows, x, y, rect_width, rect_height, color);

printf("\n \n");
printf("program finished!\n");

return 0;

}
