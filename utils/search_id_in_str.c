/*
 * @author	: wusuopubupt
 * @date	: 2014-10-21
 * @desc	: search id(int) in a string sperated by ','(comma) and ' '(blank)
 *
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int search_id(char *s, int id) {
	// 4,1,3,4,5
	int found = 0;
	char tmp[32];
	int i = 0;
	while(*s) {
		if(*s >= '0' && *s <= '9') {
			tmp[i++] = *s++;
			if(*s == '\0'){
				tmp[i] = '\0';
				if(atoi(tmp) == id) {
					found = 1;
					break;
				}
			}
		}
		else {
			tmp[i] = '\0';
			if(atoi(tmp) == id) {
				found = 1;
				break;
			}
			i = 0;
			s++;
		}
	}
	return found;
}

int main() {
	char *s = "12, 3, 4, 5, 47, 82,19,1";
	int found = search_id(s, 47);
	printf("result: %d\n", found);

	return 0;
}
