#include <stdio.h>
#include <stdlib.h>

int main(){
	int H, W, i, j;
	scanf("%d%d", &H, &W);
	char **s = (char **)malloc(sizeof(char *) * (H + 2));
	for(i = 0; i <= H + 1; i++){
		s[i] = (char *)malloc(sizeof(char) * (W + 2));
		if(i == 0 || i == H + 1){
			for(j = 0; j <= W + 1; j++){
				s[i][j] = '.';
			}
		}
		else{
			scanf("%s", &s[i][1]);
			s[i][0] = '.';
			s[i][W + 1] = '.';
		}
	}
	for(i = 1; i <= H; i++){
		for(j = 1; j <= W; j++){
			if(s[i][j] == '#' && s[i - 1][j] == '.' && s[i + 1][j] == '.' && s[i][j - 1] == '.' && s[i][j + 1] == '.'){
				printf("No\n");
				return 0;
			}
		}
	}
	printf("Yes\n");
	return 0;
}
