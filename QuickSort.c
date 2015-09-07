#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void print(int [], int);
void sort(int [], int, int);
int partition(int a[], int lo, int hi);
int isSorted(int a[], int numOfElems);
int n;
int main(int argc, char* argv[])
{
  int i;
  int *p;
  int numOfElems;
  srand(time(NULL));
  if(argc == 2)
  {
    numOfElems = atoi(argv[1]);
    p = calloc(numOfElems, sizeof(int));
    for(i = 0; i < numOfElems; i++)
    {
      p[i] = rand() % 100;
    }
    n = numOfElems;
    print(p, numOfElems);
    sort(p, 0, numOfElems-1);
    print(p, numOfElems);
    printf("Is array sorted? %d\n", isSorted(p, numOfElems));
  }
  return 0;
}

void sort(int a[], int lo, int hi)
{
  int j;
  if(lo < hi)
  {
    j = partition(a, lo, hi);
    sort(a, lo, j-1);
    sort(a, j+1, hi);
  }
}

int partition(int a[], int lo, int hi)
{
  int i = lo;
  int j = hi;
  int pivot = lo;
  int temp;
  while(1)
  {
    while(a[i] <= a[pivot])
     i++;

    while(a[j] > a[pivot])
     j--;

    if(i > j)
      break;

    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
  }

  temp = a[pivot];
  a[pivot] = a[j];
  a[j] = temp;

  return j;
}

void print(int a[], int numOfElems)
{
  int i;
  for(i = 0; i < numOfElems; i++)
  {
    printf("%d ", a[i]);
  }
  printf("\n");
}

int isSorted(int a[], int numOfElems)
{
  int i;
  for(i = 1; i < numOfElems; i++)
  {
   if(a[i-1] > a[i])
    return 0;
  }
  return 1;
}

