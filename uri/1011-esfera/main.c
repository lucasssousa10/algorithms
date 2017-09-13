#include <stdio.h>
#define PI 3.14159
int main() {
	double r, v;

	scanf("%lf", &r);
	v = (4.0/3.0)*PI*(r*r*r);

	printf("VOLUME = %.3lf\n", v);	
	return 0;
}