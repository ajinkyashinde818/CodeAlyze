/*
 * 1_1.c
 *
 *  Created on: 2018/11/20
 *      Author: masato
 */
#include <stdio.h>

int main(void){
	int n,i,x,y,max;
	scanf("%d", &n);
	scanf("%d", &x);
	max = -2147483648;
	for(i=0;i<n-1;i++){
		scanf("%d", &y);
		if(max < y - x) {
			max = y - x;
		}
		if(x > y){
			x = y;
		}
	}
	printf("%d\n", max);
}
