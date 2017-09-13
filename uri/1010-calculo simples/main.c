#include <stdio.h>

int main() {
	
	int code, amount, i;
	double value, total;

	total = 0.0;
	for(i = 0; i < 2; i++) {
		scanf("%d %d %lf", &code, &amount, &value);
		total = total + (amount * value);
	}

	printf("VALOR A PAGAR: R$ %.2lf\n", total);	
	return 0;
} 