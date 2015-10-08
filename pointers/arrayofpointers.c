#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int i = 0;
	while(i < argc)
	{
		printf("argv[%d] = %s Len = %d\n", i, argv[i], strlen(argv[i]));
		i++;
	}
	return 0;
}

