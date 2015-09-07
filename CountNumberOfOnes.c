#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[])
{
	int numOfOnes = 0;
	int input;
	int i;
	int maxBit=32;
	if(argc == 2)
	{
		input = atoi(argv[1]);
		maxBit = (int) (log10(input)/log10(2))+1;
		printf("Max Bit = %d\n", maxBit);
		/* Special case if number is a multiple of 2 */
		if((input & input-1) == 0)
		{
			numOfOnes = 1;
		}
		else
		{
			for(i = 0; i < maxBit; i++)
			{
				numOfOnes += ((input & 0x1) == 1) ? 1 : 0;
				input = input >> 1;
			}
		}	
	}
	printf("Number of Ones = %d\n", numOfOnes);
	return 0;
}

