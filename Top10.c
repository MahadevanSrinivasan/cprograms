#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void print(int[], int);
int partition(int[], int, int);
int QuickSelect(int a[], int numOfElems, int position);
int n;
#define MAX12BITNUM ((1<<12) - 1)

int main(int argc, char* argv[])
{
	int numOfElems, i=0;
	FILE *fp;
	int *p;
	if(argc == 2)
	{
		numOfElems = atoi(argv[1]);
		n = numOfElems;
  	printf("Reading back...\n");
  	fp = fopen("data.bin", "rb");
  	int datatoread;
		p = calloc(sizeof(int), numOfElems);
  	while(fread(&datatoread, 3, 1,  fp) != 0)
  	{
			p[i++] = ((datatoread>>12)&MAX12BITNUM);
			p[i++] = (datatoread&MAX12BITNUM);
  	}
  	fclose(fp);

		for(i = numOfElems-1; i > numOfElems-11; i--)
		{
			printf("Element at position %d = %d\n", i, QuickSelect(p, numOfElems, i));
		}
		for(i = 0; i < 10; i++)
		{
			printf("Element at position %d = %d\n", i, QuickSelect(p, numOfElems, i));
		}
		print(p, numOfElems);
	}
}

int QuickSelect(int a[], int numOfElems, int position)
{
	int j;
	int lo = 0;
	int hi = numOfElems-1;
	while(lo <= hi)
	{
		j = partition(a, lo, hi);
		if(j == position)
		{
			return a[j];
		}
		else if(position > j)
		{
			lo = j+1;
		}
		else
		{
			hi = j-1;
		}
	}
	return -1;
}
		
void print(int a[], int numOfElems)
{
	for(int i = 0; i < numOfElems; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int partition(int a[], int lo, int hi)
{
	int i = lo;
	int j = hi;
	int pivot = lo;

	while(1)
	{
		while(a[i] <= a[pivot] && i <= j)
			i++;

		while(a[j] > a[pivot])
			j--;

		if(j < i)
			break;

		int temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	int temp = a[lo];
	a[lo] = a[j];
	a[j] = temp;

	return j;
}

