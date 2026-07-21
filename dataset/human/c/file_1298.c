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
	int i, j, p[8], box[8], min;
	int c[8][8] = {1,2,1,2,1,4,1,4,
					1,2,1,4,1,4,1,2,
					1,4,1,2,1,2,1,4,
					1,4,1,4,1,2,1,2,
					2,1,2,1,4,1,4,1,
					2,1,4,1,4,1,2,1,
					4,1,2,1,2,1,4,1,
					4,1,4,1,2,1,2,1,
					};

	while(scanf("%d%d%d%d%d%d%d%d",&p[0],&p[1],&p[2],&p[3],&p[4],&p[5],&p[6],&p[7]) != EOF){
		
		for(i=0; i<8; i++)
			box[i] = 0;

		for(i=0; i<8; i++){
			for(j=0; j<8; j++){
				if(p[j] - c[i][j] > 0){
					box[i] += p[j] - c[i][j];
				}
			}
		}

		min = box[0];
		for(i=0; i<8; i++){
			if(min > box[i])
				min = box[i];
		}

		for(i=0; i<8; i++){
			if(box[i] == min){
				box[i] = -1;
			}
		}

		for(i=0; i<8; i++){
			if(box[i] == -1){
				for(j=0; j<8; j++){
					if(j == 0)
						printf("%d", c[i][j]);
					else
						printf(" %d", c[i][j]);
				}
				break;
			}
		}
		printf("\n");

	}

	return 0;

}
