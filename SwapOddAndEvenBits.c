#include <stdio.h>
int main(int argc, char* argv[])
{
  if(argc == 2)
  {
    int input = atoi(argv[1]);
    int mask = 0x55555555;
    int output = (input & mask) << 1 | (input & ~mask) >> 1; 
    printf("Input  = %x\n", input);
    printf("Output = %x\n", output);
  }
}
