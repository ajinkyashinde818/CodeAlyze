#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//孤立した'#'がなければ描ける

int main(void) {
	int i, j;
	int H, W;
	char **s;
	int possibility;
	int loneliness;
	char buf[128], *ch;

	fgets(buf, sizeof(buf), stdin);
	ch = strtok(buf, " ");
	H = atoi(ch);
	ch = strtok(NULL, " ");
	W = atoi(ch);

	s = (char **)calloc(H, sizeof(char *));
	for(i = 0; i < H; i += 1) {
		s[i] = (char *)calloc(W + 2, sizeof(char));
	}

	for(i = 0; i < H; i += 1) {
		fgets(s[i], sizeof(buf), stdin);
	}

	possibility = 1;
	for(i = 0; i < H; i += 1) {
		for(j = 0; j < W; j += 1) {
			if(s[i][j] == '#') {
				loneliness = 4;
				if(i == 0) {//top
					loneliness -= 1;
				} else {
					if(s[i - 1][j] == '.') {//above
						loneliness -= 1;
					}
				}
				if(i == H - 1) {//bottom
					loneliness -= 1;
				} else {
					if(s[i + 1][j] == '.') {//below
						loneliness -= 1;
					}
				}
				if(j == 0) {//leftest
					loneliness -= 1;
				} else {
					if(s[i][j - 1] == '.') {//left
						loneliness -= 1;
					}
				}
				if(j == W - 1){//rightest
					loneliness -= 1;
				} else {
					if(s[i][j + 1] == '.') {//right
						loneliness -= 1;
					}
				}
				if(loneliness == 0) {
					possibility = 0;
					break;//end j loop
				}
			}
		}
		if(possibility == 0) {
			break;//end i loop
		}
	}
	if(possibility == 1) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}

	for(i = 0; i < H; i += 1) {
		free(s[i]);
	}
	free(s);
	return 0;
}
