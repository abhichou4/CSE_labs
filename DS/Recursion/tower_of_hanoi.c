#include <stdio.h>

int i = 0;

void move(int n, char from_t, char to_t, char auxillary){

	if(n==1){
		printf("Moving %d from %c to %c\n", n, from_t, to_t);
		i++;
		return;
	}
	
	move(n-1, from_t, auxillary, to_t);
	printf("Moving %d from %c to %c\n", n, from_t, to_t);
	i++;
	move(n-1, auxillary, to_t, from_t);
}

int main(){
	int n, steps;
	printf("Enter number of discs\n");
	scanf("%d", &n);
	char from_t='a', to_t='b', auxillary='c';
	move(n, from_t, to_t, auxillary);
	printf("%d\n", i);
	return 0;
}