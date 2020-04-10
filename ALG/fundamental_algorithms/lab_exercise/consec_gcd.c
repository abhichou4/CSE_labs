#include <stdio.h>

int gcd(int m, int n) {
	int k = (m < n) ? m : n;
	while (m%k == 0 && n%k == 0)
		k--;
	return k;
}

int main(void) {
	int m, n;
	printf("Enter numbers:\n");
	scanf("%d %d", &m, &n);
	printf("GCD: %d\n", gcd(m,n));
	return 0;
}