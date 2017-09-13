#include <stdio.h>

int main() {
	int number, hours;
	double value;

	scanf("%d", &number);
	scanf("%d", &hours);
	scanf("%lf", &value);
	
	printf("NUMBER = %d\n", number);
	printf("SALARY = U$ %.2lf\n", hours * value);
	
	return 0;
}