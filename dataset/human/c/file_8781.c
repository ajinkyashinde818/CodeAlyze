#include <stdio.h>

int main() {
	char v[50+2][50+2];
	int h, w;
	scanf("%d%d", &h, &w);
	for (int i = 0; i <= w + 1; i++) {
		if ( i == 0 || i == w+1) {
			for (int j = 1; j <= h; j++) {
				v[i][j] = '.';
			}
		} else {
			char s[51];
			scanf("%s", s);
			v[i][0] = v[i][h+1] = '.';
			for (int j = 1; j <= h; j++) {
				v[i][j] = s[j-1];
			}
		}
	}


	for (int i = 1; i < w; i++) {
		for (int j = 1; j < h; j++) {
			if( v[i][j] == '#') {
				if (v[i+1][j] == '.') {
				if (v[i-1][j] == '.') {
				if (v[i][j+1] == '.') {
				if (v[i][j-1] == '.') {
					printf("No\n");
					return 0;
				}}}}
			}
		} 
	}
	printf("Yes\n");	
	return 0;
}
