// An Easy Problem
// http://community.topcoder.com/stat?c=problem_statement&pm=13527

#include <stdio.h>
#include <math.h> /* Need for sqrt & floor */
#include <stdlib.h> /* Needed for atoll */

long solve(long);
long solve(long sum)
{
  long h, r;
  long min = -1;
  long startr, endr, temp;
  long hfactor, rfactor;

  long starth = (long) sqrt(sum);
  long endh = (long) floor(((sqrt(8*sum+1)+1)/2));
  for(h = starth; h <= endh; h++)
  {
    hfactor = h * h;
    temp = (long) floor(sqrt(8*hfactor-8*sum+1));
    startr = (long)(temp - 1)/ 2;
    endr = (long)(temp + 1)/ 2;

    for(r = startr; r <= endr; r++)
    {
      rfactor = r*(r-1)/2;
      if((hfactor - rfactor) == sum)
      {
        if(min == -1 || min > (2*h - r))
          min = 2*h -r;
      }
    }
  }
  return min;
}

int main(int argc, char* argv[])
{
  if(argc == 2)
  {
    //long sum = 1000000000000;
    long sum = atoll(argv[1]);
    printf("Solution = %ld\n", solve(sum));
  }
}
