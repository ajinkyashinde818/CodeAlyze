#include <stdio.h>
#include <stdlib.h>

int main() {
	int num;
	int count = 0;
	
	/*** loop ***/
	while (count < 10000) {
		/** scan **/
		scanf("%d", &num);
		
		/** judge **/
		if (!(num >= 1 & num <= 10000)) {
			if (num == 0) break;
			printf("error\n");
			exit(1);
		}
		
		/** print **/
		printf("Case %d: %d\n", count + 1, num);
		count++;
	}
	
	return 0;
	
}
