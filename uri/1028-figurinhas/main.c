#include <iostream>
 
using namespace std;
int mdc(int *x, int *y);
int main() {
 
   int numberOfCases, a, b, i;

	scanf("%d", & numberOfCases);

	for(i = 0; i < numberOfCases; i++) {
		scanf("%d %d", &a, &b);
	 	printf("%d\n", mdc(&a, &b));
	}
	return 0;
}

int mdc(int *x, int *y) {
	
	if( *x<0 ) *x = -*x;
    if( *y<0 ) *y = -*y;

	while(*y != 0) {
		*x = *x % *y;
		if(*x == 0){return *y;}
		*y = *y % *x;
	}

	return *x;
}
