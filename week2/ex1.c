#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <limits.h>
int main(){
	int a;
	float b;
	double c;
	a = INT_MAX;
	b = FLT_MAX;
	c = DBL_MAX;
	printf("%s%d%s","Max of int \n",a,"\n");
	printf("%s%f%s","Max of float \n",b,"\n");
	printf("%s%lf%s","Max of double \n",c,"\n");
}
