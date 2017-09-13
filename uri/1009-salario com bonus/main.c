#include <stdio.h>
#define SIZE_NAME 100

int main() {
	
	char name[SIZE_NAME];
	double salary, sales, payment;

	scanf("%s", name);
	scanf("%lf", &salary);
	scanf("%lf", &sales);
	
	payment = salary + (0.15*sales);
	printf("TOTAL = R$ %.2lf\n", payment);
		
	return 0;
} 