#include <stdio.h>

int main() {
	int h, w;
	scanf("%d %d", &h, &w);
	char data[51][51];
	int flag = 1;
	for (int i = 1; i <= h; i++) {
		//for (int j = 1; j <= w; j++) {
			scanf("%s", &data[i][1]);
		//}
		//scanf("\n");
	}
	for (int i = 2; i < h; i++) {
		for (int j = 2; j < w; j++) {
			if (data[i][j] == '#') {
				if (!(data[i - 1][j] == '#' || data[i + 1][j] == '#' || data[i][j - 1] == '#' || data[i][j + 1] == '#'))flag = 0;
			}
		}
	}
	for (int i = 2; i < h; i++) {
		if (data[i][1] == '#') {
			if (!(data[i][2] == '#' || data[i - 1][1] == '#' || data[i + 1][1] == '#'))flag = 0;
		}
		if (data[i][w] == '#') {
			if (!(data[i][w - 1] == '#' || data[i - 1][w] == '#' || data[i + 1][w]=='#'))flag = 0;
		}

	}
	if (data[1][1] == '#') {
		if (!(data[2][1] == '#' || data[1][2] == '#'))flag = 0;
	}
	if (data[1][w] == '#') {
		if (!(data[2][w] == '#' || data[1][w-1] == '#'))flag = 0;
	}
	if (data[h][1] == '#') {
		if (!(data[h-1][1] == '#' || data[h][2] == '#'))flag = 0;
	}
	if (data[h][w] == '#') {
		if (!(data[h-1][2] == '#' || data[h][w-1] == '#'))flag = 0;
	}
	
	for (int j = 2; j < w; j++) {
		if (data[1][j] == '#') {
			if (!(data[1][j-1] == '#' || data[2][j] == '#' || data[1][j+1] == '#'))flag = 0;
		}
		if (data[h][j] == '#') {
			if (!(data[h][j - 1] == '#' || data[h-1][j] == '#' || data[h][j+1] == '#'))flag = 0;
		}
	}
	if (flag) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}
	return 0;
}
