#include <stdio.h>
int main(void){
	char e[51][51];
	int i, j,a,b,c=0;
	scanf("%d %d", &a, &b);
	for (i = 0; i < a; i++){
		for (j = 0; j < b+1; j++){
			scanf("%c", &e[i][j]);
		}
	}
	for (i = 0; i < a; i++){
		for (j = 0; j < b+1; j++){
			if (e[i][j] == '#'&&e[i - 1][j] != '#'&&e[i + 1][j] != '#'&&e[i][j + 1] != '#'&&e[i][j - 1] != '#'){
				c++;
			}
		}
	}
	if (c == 0){
		printf("Yes");
	}
	else{
		printf("No");
	}
	return 0;
}
