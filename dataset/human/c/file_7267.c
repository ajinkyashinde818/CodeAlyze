#include <stdio.h>
#include <stdlib.h>

bool DP[80][80][(80+80)*80];
int main()
{
	int H,W;
	int G1[80][80];
	int G2[80][80];
	
	scanf("%d %d", &H, &W);
	for(int i = 0; i < H; i++){
		for(int j = 0; j < W; j++){
			scanf("%d", &G1[i][j]);
		}
	}
	
	for(int i = 0; i < H; i++){
		for(int j = 0; j < W; j++){
			scanf("%d", &G2[i][j]);
		}
	}
	
	for(int i = 0; i < H; i++){
		for(int j = 0; j < W; j++){
			for(int k = 0; k < (H+W)*80; k++){
				DP[i][j][k] = false;
			}
		}
	}
	
	// ここから解法
	for(int i = 0; i < H; i++){
		for(int j = 0; j < W; j++){
			int diff = abs(G1[i][j] - G2[i][j]);
			if(i == 0 && j == 0){
				DP[i][j][diff] = true;
			}
			else{
				if(i > 0) {
					for(int k = 0; k < (H+W)*80; k++){
						if(DP[i-1][j][k]){
							int up = k + diff;
							int down = abs(k - diff);
							DP[i][j][up] = true;
							DP[i][j][down] = true;
						}
					}
				}
				if(j > 0) {
					for(int k = 0; k < (H+W)*80; k++){
						if(DP[i][j-1][k]){
							int up = k + diff;
							int down = abs(k - diff);
							DP[i][j][up] = true;
							DP[i][j][down] = true;
						}
					}
				}
			}
		}
	}
	
	int min = (H+W)*80;
	for(int k = 0; k < (H+W)*80; k++){
		if(DP[H-1][W-1][k]){
			min = k;
			break;
		}
	}
	
	printf("%d\n", min);
	return 0;
}
