#include <stdio.h>

void printarray(int *p, int length)
{
	int i = 0;
	for (i = 0; i < length; i++)
	{
		printf("Addr: %p, Value: %d\n", p, *p);
		p++;
	}
}

int main(void)
{
	int array[] = {1, 2, 3, 4, 5, 6};
	printarray(array, sizeof(array)/ sizeof(int));
	return 0;
}
