#include <stdio.h>
int abs(int a);
int main() {

	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	a = (a + b + abs(a - b)) / 2;
	a = (a + c + abs(a - c)) / 2;

	printf("%d eh o maior\n", a);
	return 0;
}
int abs(int a) {
	if(a > 0) {
		return a;
	} else {
		return -a;
	}
}