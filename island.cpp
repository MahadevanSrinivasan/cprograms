/**
 * Solution to the problem at the following link:
 * http://www.geeksforgeeks.org/find-number-of-islands/ 
 */
#include<stdio.h>
/**
 * Is the element at (r, c) valid and if
 * (r, c) is valid index.
 */
int iev(int a[5][5], int r, int c)
{
  return ((r >= 0) && (r < 5) && (c >= 0) && (c < 5) && (a[r][c] == 1));  
}

/**
 * Is element at (r, c) part of a component?
 */
int iepoac(int a[5][5], int r, int c)
{
  return (a[r][c] == 0)    ||
    iev(a, r-1, c-1) ||
    iev(a, r-1, c)   ||
    iev(a, r, c-1)   ||
    iev(a, r-1, c+1);
}

int main()
{
  int a[5][5] = {{1, 1, 0, 0, 0},
                 {0, 1, 0, 0, 1},
                 {1, 0, 0, 1, 1},
                 {0, 0, 0, 0, 0},
                 {1, 0, 1, 0, 1}};
  int i, j, count = 0;
  for(i = 0; i < 5; i++) {
    for(j = 0; j < 5; j++) {
      count = (iepoac(a, i, j)) ? count : (count+1);
    }
  }
  printf("%d\n", count);
  return 0;
}
