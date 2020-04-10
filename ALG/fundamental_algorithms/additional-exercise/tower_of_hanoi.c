#include <stdio.h>


int count = 0;

void tower_of_hanoi(int n) {
	char from='A', to='B', aux='C';
	if (n == 1) { 
		printf("Move one from %c to %c directly\n", from, to);
		count++;
		return;	
	}
	printf("Move %d from %c to %c\n", n-1, from, aux);
	tower_of_hanoi(n-1);
	printf("Move one from %c to %c directly\n", from , to);
	count++;
	tower_of_hanoi(n-1);
	printf("Move %d from %c to %c\n", n-1, aux, to);
}

int main(void) {
	int n;
	printf("Enter number of discs:\n");
	scanf("%d", &n);
	tower_of_hanoi(n);
	printf("count: %d\n", count);
}