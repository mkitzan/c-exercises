#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

enum state { SUCCESS, COMP_FAIL, NULL_FAIL, LEN_FAIL }; 

enum state rle(char *str) {
	if(!str)
		return NULL_FAIL;
	size_t len = strlen(str), count = 1, n = 0;
	char *comp, curr;
	
	if(len < 2) 
		return LEN_FAIL;

	comp = (char *) malloc((len + 1) * sizeof(char));
	if(!comp)
		exit(1);

	curr = str[0];
	
	for(size_t i = 1; i < len; ++i) {
		if(str[i] != curr) {
			if(n + 2 > len) {
				free(comp);
				return COMP_FAIL;
			}
			comp[n++] = curr;
			comp[n++] = count;
			curr = str[i];
			count = 1;
		} else {
			++count;
		}
	}

	if(n + 2 > len) {
		free(comp);
		return COMP_FAIL;
	}

	comp[n++] = curr;
	comp[n++] = count;
	comp[n++] = '\0';

	strncpy(str, comp, n);
	free(comp);

	return SUCCESS;
}

int main() {
	char lenf[32] = "*";
	char test[32] = "aabccccddd";
	char fail[32] = "this is will not compress";
	printf("%s\n", test);
	assert(rle(test) == SUCCESS);
	printf("%s\n\n%s\n", test, fail);
	assert(rle(fail) == COMP_FAIL);
	printf("%s\n", fail);
	assert(rle(NULL) == NULL_FAIL);
	assert(rle(lenf) == LEN_FAIL);
	return 0;
}

