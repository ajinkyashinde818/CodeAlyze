// AOJ Volume 0 Problem 0082

#include <stdio.h>
#include <string.h>

int main(void)
{
	int guest[8];
	int ride[] = {4, 1, 4, 1, 2, 1, 2, 1,   4, 1, 4, 1, 2, 1, 2, 1,   4 , 1};
	int min_ride[8];
	int i, j;
	int remain, min_remain;
	
	while (scanf("%d%d%d%d%d%d%d%d", 
					&guest[0], &guest[1], &guest[2], &guest[3], 
					&guest[4], &guest[5], &guest[6], &guest[7]) != EOF){

		min_remain = 999999999;
		min_ride[0] = min_ride[1] = min_ride[2] = min_ride[3] = 
		min_ride[4] = min_ride[5] = min_ride[6] = min_ride[7] = 9;
		for (i = 0; i < 8; i++){
			remain = 0;
			for (j = 0; j < 8; j++){
//			printf("(%d %d)", guest[j], ride[i + j]);
				if (ride[i + j] < guest[j]){
//					printf("[%d]", (guest[j] - ride[i + j]));
					remain += (guest[j] - ride[i + j]);
				}
			}
//			printf("\n<%d %d>\n", i, remain);
			if (min_remain > remain){
				min_remain = remain;
				memcpy(min_ride, &ride[i], sizeof(int) * 8);
			}
			else if (min_remain == remain){
				for (j = 0; j < 8; j++){
					if (min_ride[j] > ride[j + i]){
						memcpy(min_ride, &ride[i], sizeof(int) * 8);
						break;
					}
					else if (min_ride[j] < ride[j + i]){
						break;
					}
				}
			}
		}
		printf("%d %d %d %d %d %d %d %d\n",
				min_ride[0], min_ride[1], min_ride[2], min_ride[3],
				min_ride[4], min_ride[5], min_ride[6], min_ride[7]);
	}
	return (0);
}
