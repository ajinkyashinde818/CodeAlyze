/*
 * hello.c
 *
 *  Created on: 2013/04/19
 *      Author: PC user
 */

#include <stdio.h>

int main(){
	int w,h,i,j;
	while(1){
		scanf("%d %d",&h,&w);
		if(h==0 && w==0){
			break;
		}
		for(i=0;i<h;i++){
			for(j=0;j<w;j++){
				if(j%2 == 0){
					if(i%2 == 0)printf("#");
					else printf(".");
				}
				else{
					if(i%2 == 0) printf(".");
					else printf("#");		
				}
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
