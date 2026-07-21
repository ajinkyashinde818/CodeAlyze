#include <stdio.h>
#include <stdlib.h>
#define S(x, y) (x>=0 && x<h && y>=0 && y<w ? s[y][x] : '.')

int main(void) {
	char **s;
	int h, w, i, j;
	int flag = 0;
	
	scanf("%d %d", &h, &w);
	s = malloc(sizeof(char) * (h));
	
	for (i = 0; i < h; i++) {
		s[i] = malloc(sizeof(char) * (w));
		for (j = 0; j < w; j++) {
			scanf(" %c", &s[i][j]);
			if (S(j, i-1) == '#') {
				if (S(j-1, i-1) != '#' && S(j,i-2) != '#' &&
					S(j+1, i-1) != '#' && S(j, i) != '#') {
					flag = 1;
				}
			}
		}
	}
	
	printf(flag ? "No" : "Yes");
	
	return 0;
}
