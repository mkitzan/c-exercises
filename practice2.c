#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct string {
	
	char *line;
	int length;
} String;

int length(char *str) {
	
	char *point;
	
	for(point = str; *point; point++);
	
	return point - str;
}

int char_diff(int index, char *str1, char *str2) {
	
	return *(str1+index) - *(str2+index);
}

int index_diff(char *str1, char *str2) {
	
	char *point1;
	char *point2;

	for(point1 = str1, point2 = str2; *point1 == *point2; point1++, point2++);
	
	return point1 - str1;
}

int comp(char *str1, char *str2) {
	
	int diff = index_diff(str1, str2);
	int str1_length = length(str1);
	int str2_length = length(str2);
	
	if(diff == str1_length+1 || diff == str2_length+1) {
		return 0;
	}
	return char_diff(diff, str1, str2);
}

int main(int argc, char *argv[]) {
	
	if(argc < 3) {
		return 1;
	}
	
	String str1;
	String str2;
	
	str1.line = argv[1];
	str2.line = argv[2];
	
	str1.length = length(str1.line);
	str2.length = length(str2.line);
	int diff = index_diff(str1.line, str2.line);
	
	printf("str1: %s len: %d\nstr2: %s len: %d\nind dif: %d\n", str1.line, str1.length, str2.line, str2.length, diff);
	
	diff = comp(str1.line, str2.line);

	printf("str dif: %d\n\n", diff);
	
	if(diff < 0) {
		printf("%s, %s\n", str1.line, str2.line);
	} else {
		printf("%s, %s\n", str2.line, str1.line);
	} 
	return 0;
} 