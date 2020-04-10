#include <stdio.h>

int gcd(int m, int n) {
	int a, b, r;
	if (m > n) {a = m; b = n;}
	else {a = n; b = m;}
	r = a % b;
	if (r == 0) 
		return b;
	return gcd(b, r);
}

int main(void) {
	int m, n;
	printf("Enter two numbers:\n");
	scanf("%d %d", &m, &n);
	printf("GCD: %d\n", gcd(m,n));
	return 0;
}