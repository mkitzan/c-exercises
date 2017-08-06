#include <stdio.h>

int main() {
	
	int num, div, quo=0;
	
	printf("Enter num and div: ");
	scanf("%d %d", &num, &div);
	
	int arr[num];
	int *point = arr;
	
	for(; num>=div; num-=div) {
		*point++ = num;
		quo++;
	}
	*point = num;
	
	printf("Quo: %d\nRem: %d\n", quo, num);
	
	int *i;
	for(i = arr; i<=point; i++) {
		printf("%d ", *i);
	}
	
	return 0;
}