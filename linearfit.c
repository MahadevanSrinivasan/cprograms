/**
  * Linear Fitting example
  * Data: http://www.stat.wmich.edu/s216/book/node126.html 
  */
#include <stdio.h>
#include <math.h>

int main(void)
{
	int miles[] = {9300, 10565, 15000, 15000, 17764,
		       57000, 65940, 73676, 77006, 93739,
		       146088, 153260};
	int price[] = {7100, 15500, 4400, 4400, 5900, 4600,
		8800, 2000, 2750, 2550, 960, 1025};
	int size = 12;
	/* Sticking to integer arithmetic */
	int xbar = 0, ybar = 0;
	long long stddevx = 0, stddevy = 0; 
	float r = 0;
	int i = 0;

	printf("int = %d, long = %d, long long = %d, long long int = %d\n",
		sizeof(int), sizeof(long), sizeof(long long), sizeof(long long int));

	for(i = 0; i < size; i++)
	{
		xbar += miles[i];
		ybar += price[i];
	}
	xbar = xbar / size;
	ybar = ybar / size;
	printf("Mean(X) = %d, Mean(Y) = %d\n", xbar, ybar);
	for(i = 0; i < size; i++)
	{
		stddevx += (long long) (miles[i] - xbar) * (miles[i] - xbar);
		stddevy += (long long) (price[i] - ybar) * (price[i] - ybar);
	}
	long long temp = sqrt(stddevx) * sqrt(stddevy);
	stddevx = sqrt(stddevx/(size-1));
	stddevy = sqrt(stddevy/(size-1));
	printf("Stddev(X) = %lld, Stddev(Y) = %lld\n", stddevx, stddevy);

	for(i = 0; i < size; i++)
	{
		r += (float) (miles[i] - xbar) * (price[i] - ybar);
	}
	r = r / temp;

	printf("r = %.2f\n", r);
	float m = (r * stddevy) / stddevx;
	printf("m = %.2f\n", m); 
	printf("c = %.2f\n", ybar - m * xbar);

	return 0;
}	

