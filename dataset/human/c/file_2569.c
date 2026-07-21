/*
 * A.c
 *
 *  Created on: 2018/04/16
 *      Author: Haruyuk1
 */

#include <stdio.h>

int main(void){
	char string[4];
	int i, j, k, res;
	res = 0;

	scanf("%s", string);

	for (i = 0; i <= 2; i++){
		if (string[i] == 'a'){
			for (j = 0; j <= 2; j++){
				if (string[j] == 'b'){
					for (k = 0; k <= 2; k++){
						if (string[k] == 'c'){
							res = 1;
						}
					}
				}
			}
		}
	} if (res == 1){
		printf("Yes");
	} else {
		printf("No");
	}
	return 0;
}
