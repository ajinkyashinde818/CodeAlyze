#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdarg.h>
#include<malloc.h>

int main()
{
	int h, w, i, j;

	while(1){

		scanf("%d %d", &h, &w);

		if(h == 0 && w == 0)
			break;

		for(i = 0; i < h; i++){
			if(i % 2 == 0){
				for(j = 0; j < w; j++){
					if(j % 2 == 0)
						printf("#");
					else
						printf(".");
				}
			}
			else{
				for(j = 0; j < w; j++){
					if(j % 2 == 0)
						printf(".");
					else
						printf("#");
				}
			}
			printf("\n");
		}
		printf("\n");
	}

	return 0;
}
