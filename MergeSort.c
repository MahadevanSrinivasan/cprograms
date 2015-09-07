#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void print(int [], int);
void sort(int [], int [], int, int);
int isSorted(int a[], int numOfElems);
void merge(int a[], int b[], int lo, int mid, int hi);
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
    //p = calloc(numOfElems, sizeof(int));
    int a[numOfElems], b[numOfElems];
    for(i = 0; i < numOfElems; i++)
    {
      a[i] = rand() % 10000;
      b[i] = a[i];
    }
    n = numOfElems;
    //print(a, numOfElems);
    sort(a, b, 0, numOfElems-1);
    //print(a, numOfElems);
    printf("Is array sorted? %d\n", isSorted(a, numOfElems));
  }
  return 0;
}

void sort(int a[], int b[], int lo, int hi)
{
  int j;
  if(lo < hi)
  {
    int mid = (lo + hi) / 2;
    sort(a, b, lo, mid);
    sort(a, b, mid+1, hi);
    merge(a, b, lo, mid, hi);
    //print(a, n);
  }
}

void merge(int a[], int b[], int lo, int mid, int hi)
{
  int k = lo;
  int leftEnd = mid;
  int rightEnd = hi;
  int right = mid+1;
  int num = rightEnd - lo + 1;

  while(lo <= leftEnd && right <= rightEnd)
  {
    if(a[lo] < a[right])
    {
      b[k++] = a[lo++];
    }
    else
    {
      b[k++] = a[right++];
    }
  }

  while(lo <= leftEnd)
  {
    b[k++] = a[lo++];
  }

  while(right <= rightEnd)
  {
    b[k++] = a[right++];
  }

  while(num >= 0)
  {
    a[right] = b[right];
    right--;
    num--;
  }
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

