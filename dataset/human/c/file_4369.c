#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	const char *SEP = " ";
	int n, d1, d2, cnt, result;
	char input_str[12 * 200000];
	char *num_str;
	int i;

	fgets(input_str, sizeof(input_str), stdin);
	num_str = strtok(input_str, SEP);
	n = atoi(num_str);

	result = 0;
	cnt = 0;
	for ( i = 0; i < n; i++ ) {
		fgets(input_str, sizeof(input_str), stdin);
		num_str = strtok(input_str, SEP);
		d1 = atoi(num_str);
		
		num_str = strtok(NULL, SEP);
		d2 = atoi(num_str);

		if ( d1 == d2 ) {
			cnt++;
			if ( 3 <= cnt ) {
				result = 1;
			}
		}
		else {
			cnt = 0;
		}
	}

	if ( result ) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}

	return 0;
}
