#include <stdio.h>
int main() {
	int dist;
	double cons;

	scanf("%d", &dist);
	scanf("%lf", &cons);

	printf("%.3lf km/l\n", dist/cons);

	return 0;
}