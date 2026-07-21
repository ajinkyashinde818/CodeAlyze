/*
 ============================================================================
 Name        : AtCoder_A.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char text[3];
	int a=0,b=0,c=0;
	int i;

	scanf("%s",text);

	for(i=0; i<3; i++){
		if(text[i]== 'a'){
			a=1;
		}
		if(text[i]== 'b'){
					b=1;
		}
		if(text[i]== 'c'){
					c=1;
		}
	}

	if( (a+b+c) ==3){
		printf("Yes");
	}else{
		printf("No");
	}
	return EXIT_SUCCESS;
}
