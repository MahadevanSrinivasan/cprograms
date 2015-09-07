/**
 * This program shows the effect of byte/word alignment
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX12BITNUM ((1<<12)-1)

int main(int argc, char* argv[])
{
  FILE *fp, *fp2;
  int r, datatowrite, i;
	if(argc == 2)
	{
		int numOfElems = atoi(argv[1]);
  	fp = fopen("data.bin", "wb");
		fp2 = fopen("data.txt", "w");
  	srand(time(NULL));
  	for(i = 0; i < numOfElems; i++)
  	{
 			r = (rand() % MAX12BITNUM);
 			datatowrite = r << 12;
			fprintf(fp2, "%d\n", r);
 			printf("first=%d\t", r);
 			r = (rand() % MAX12BITNUM);
 			printf("second=%d\n", r);
			fprintf(fp2, "%d\n", r);
 			datatowrite = datatowrite | r;
			fwrite(&datatowrite, 3, 1, fp);
  	}
  	fclose(fp);
		fclose(fp2);
	}
#if 0
  printf("Reading back...\n");
  fp = fopen("temp.bin", "rb");
  int datatoread;
  while(fread(&datatoread, 3, 1,  fp) != 0)
  {
    printf("first=%d\tsecond=%d\n", ((datatoread>>12)&MAX12BITNUM), (datatoread&MAX12BITNUM));
  }
  fclose(fp);
#endif
  return 0;
}
