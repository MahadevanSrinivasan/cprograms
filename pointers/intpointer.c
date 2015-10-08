#include <stdio.h>

void printvalueofx(int *p)
{
	printf("printvalueof: Addr: %p,  Value = %d\n", p, *p);
}

int main(void)
{
	int x = 12;
	int *p = &x;

	printf("x = %d\n", x);
	*p = 42;
	printf("main: Addr: %p, Value = %d\n", p, *p);
	/* Pass the pointer to the function */
	printvalueofx(p);

	return 0;
}

