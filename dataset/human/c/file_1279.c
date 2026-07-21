#include <stdio.h>

int main(void)
{
	int go_round[8] = {1, 2, 1, 2, 1, 4, 1, 4};
	int client[8];
	int minimum[8], min, temp;
	int seisuu;
	int i, j;
	int temp_s;
	
	while (scanf("%d%d%d%d%d%d%d%d", &client[0], &client[1], &client[2], &client[3], &client[4], &client[5], &client[6], &client[7]) != EOF){
		
		
		for (i = 0; i < 8; i++){
			temp = temp_s = 0;
			for (j = 0; j < 8; j++){
				temp += (client[j] - go_round[(i + j) % 8] > 0) ? (client[j] - go_round[(i + j) % 8]) : 0;
				temp_s = temp_s * 10 + go_round[(i + j) % 8];
			}
			if (temp <= min || i == 0){
				if (temp == min && i != 0){
					if (temp_s < seisuu){
						min = temp;
						seisuu = temp_s;
						for (j = 0; j < 8; j++){
							minimum[j] = go_round[(i + j) % 8];
						}
					}
				}
				else {
					min = temp;
					seisuu = temp_s;
					for (j = 0; j < 8; j++){
						minimum[j] = go_round[(i + j) % 8];
					}
				}
			}
		}
		
		for (i = 0; i < 8; i++){
			if (i != 0){
				printf(" ");
			}
			printf("%d", minimum[i]);
		}
		
		printf("\n");
	}
	
	return (0);
}
