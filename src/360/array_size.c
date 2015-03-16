#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(void) {

	char       str1[7] = "abcdefg";
	//char       str1[] = "abcdefg";
	char       str2[] = {'a', 'b','c','d', 'e', 'f','g', '\0'};
	char  *a = "xxx";
	char       str3[] = "120345";
	size_t str1_size = sizeof(str1);
	size_t str2_size = sizeof(str2);
	//size_t str3_size = sizeof(str3);
	size_t str1_len = strlen(str1);
	size_t str2_len = strlen(str2);
	//size_t str3_len = strlen(str3);

	printf("str1: '%s', len: %d, size: %d\n", str1, str1_len, str1_size);
	printf("str2: '%s', len: %d, size: %d\n", str2, str2_len, str2_size);
	//printf("str3: '%s', len: %d, size: %d\n", str3, str3_len, str3_size);
	printf("str2[8]: %c\n", str2[8]);

	
	if(str1[7] == '\0') {
		printf("str1[7]==\\0\n");
	}
	if(str2[7] == '\0') {
		printf("str2[7]==\\0\n");
	}
	
	//if(str1[]

	

	return 0;

}
