/**
  * Linear Fitting example
  * Data: http://www.stat.wmich.edu/s216/book/node126.html 
  */
#include <stdio.h>
#include <math.h>

int linearfit(int x[], int y[], int size)
{
	/* Sticking to integer arithmetic */
	int xbar = 0, ybar = 0;
	long long stddevx = 0, stddevy = 0; 
	double r = 0;
	int i = 0;

	for(i = 0; i < size; i++)
	{
		xbar += x[i];
		ybar += y[i];
	}
	xbar = xbar / size;
	ybar = ybar / size;
	printf("Mean(X) = %d, Mean(Y) = %d\n", xbar, ybar);
	for(i = 0; i < size; i++)
	{
		stddevx += (long long) (x[i] - xbar) * (x[i] - xbar);
		stddevy += (long long) (y[i] - ybar) * (y[i] - ybar);
	}
	long long temp = sqrt(stddevx) * sqrt(stddevy);
	stddevx = sqrt(stddevx/(size-1));
	stddevy = sqrt(stddevy/(size-1));
	printf("Stddev(X) = %lld, Stddev(Y) = %lld\n", stddevx, stddevy);

	for(i = 0; i < size; i++)
	{
		r += (double) (x[i] - xbar) * (y[i] - ybar);
	}
	r = r / temp;

	printf("r = %.2f\n", r);
	float m = (r * stddevy) / stddevx;
	printf("m = %.2f\n", m); 
	printf("c = %.2f\n", ybar - m * xbar);

	/* Another way of computing it */
	long long num = 0, den = 0;
	for(i = 0; i < size; i++)
	{
		printf("Num = %lld, Den = %lld\n", num, den);
		printf("x[i] = %d, y[i] = %d\n", x[i], y[i]);
		num += (long long) (x[i] - xbar) * (y[i] - ybar);
		den += (long long) (x[i] - xbar) * (x[i] - xbar);
	}
	printf("Num = %lld, Den = %lld\n", num, den);
	m = (float) num / den;
	printf("m = %.2f\n", m);
	printf("c = %.2f\n", ybar - m * xbar);
	return 0;
}	

int main()
{
	int x[] = {9300, 10565, 15000, 15000, 17764,
		       57000, 65940, 73676, 77006, 93739,
		       146088, 153260};
	int y[] = {7100, 15500, 4400, 4400, 5900, 4600,
		8800, 2000, 2750, 2550, 960, 1025};
	int size = 12;

	//linearfit(x, y, size);
	int x1[] = {-5, -4, -3, -2, -1};
	int y1[] = {30822, 30924, 31027, 31129, 31232};
	linearfit(x1, y1, 5);

	return 0;
}

