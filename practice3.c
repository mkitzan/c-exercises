#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *arr, int len) {
	
	int i, j, temp;
	for(i = 0; i<len; i++) {
		for(j = 0; j<len; j++) {
			if(*(arr+i) < *(arr+j)) {
				temp = *(arr+i);
				*(arr+i) = *(arr+j);
				*(arr+j) = temp; 
			}
		}
	}
}

void selection_sort(int *arr, int len) {
	
	int i, j, small;
	for(i=0; i<len; i++) {
		for(small=i+1, j=i+2; j<len; j++) {
			if(*(arr+small) > *(arr+j)) {
				small = j;
			}
		}
		if(*(arr+i) > *(arr+small)) {
			j = *(arr+i);
			*(arr+i) = *(arr+small);
			*(arr+small) = j;
		}
		
	}
}

int main(int argc, char *argv[]) {
	
	int arr[argc];
	int i;
	
	for(i = 1; i<argc; i++) { 
		arr[i-1] = strtol(argv[i], NULL, 10);
	}
	
	//bubble_sort(arr, argc-1);
	selection_sort(arr, argc-1);
	
	for(i = 0; i<argc-1; i++) {
		printf("%d ", arr[i]);
	}
	
	return 0;
}