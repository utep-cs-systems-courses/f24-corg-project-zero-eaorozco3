#include <stdio.h>
#include "draw.h"

/* Prints a size x size square whose left col is at startCol */
void print_square(int leftCol, int size)
{
  int i, j;
  int endCol = leftCol + size;
  for (int row = 0; row < size; row++){
    int col;
    for (col = 0; col < leftCol; col++) putchar(' ');
    for (       ; col < endCol;  col++) putchar('*');
    putchar('\n');
  }
}

// Prints a triangle of specified height whose left edge is at col leftCol.
void print_triangle(int leftCol, int size)
{
  for (int row = 0; row <= size; row++) {
    int minCol = leftCol + size - row, maxCol = leftCol + size + row;
    int col;
    for (col = 0; col < minCol; col++) putchar(' ');
    for (       ; col <= maxCol; col++) putchar('*');
    putchar('\n');
  }
}

// Prints an arrow of specific length and arrowhead size.
void print_arrow(int length, int size) {
  int reachSize = 1;
  int reachedHalf = 0;
  
  for(int i = 0; i < length; i++) {
    // If i is half the stated length, print a full line denoting the arrow shaft.
    if(i == length / 2) {
      for(int j = 0; j < length; j++) {
	putchar('*');
      }
    }

    // Print empty space. But keep the appropriate space to print the arrowhead after.
    else {
      for(int j = 0; j < length; j++) {
	putchar(' ');
      }
    }

    // i will depend on reachSize, which will decrease or increase depending on arrowhead.
    for(int i = 0; i < reachSize && reachSize > 0; i++) {
      putchar('*');
    }

    // Once half of the arrowhead reached, stars are printed in decremental order.
    reachSize == size / 2 || reachedHalf ? reachSize--, reachedHalf = 1 : reachSize++;
    
    putchar('\n');
  }
}

