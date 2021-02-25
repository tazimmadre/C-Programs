#include <stdio.h>
#include<math.h>
/* Propram to perform definite integration of a given function between
   two boundary limits input by user. Feel free to use and modify it, but
   please do not remove this comment.
   source: C for Engineering, http://c4engineering.hypermart.net */

#define N 1000

void main(void)
{
	double i, a=-5, b=5,delta=0.001,z,x=1.5,y, sum = 0;
	printf("\nr Integration (summation) of function y=2x^4+x is /n");
	for(i = a; i < b-delta; i += delta)
	{
		/* Define your function	below, and include the suitable header files */
		
		y=(2*pow(x,5))/5+pow(x,2)/2;
		sum += y;
	printf("\n\nValue of integration is:%.3f", sum);
	}

	printf("\n\nValue of integration is:%.3f", sum);
	return;
}
