#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Newton-Rhapson Method
float square_root(float n) {
	float root = n/2;
	float e = 0.0001;
	while (fabs(root*root - n) > e) {
		if (root*root > n)
			root = n/root;
		else 
			root = (root + n/root) / 2.0;
	}

	return root;
}

int main(void) {
	float n;
	printf("Enter a number:\n");
	scanf("%f", &n);
	printf("Root: %f\n", square_root(n));
}