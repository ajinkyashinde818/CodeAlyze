#include <stdio.h>
#include <stdlib.h>

char map[55][55];
int h, w;
int f = 1;

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

int isLinked(int h, int w);

int main()
{

	scanf("%d %d", &h, &w);
	for (int i = 0; i < h; i++) {
		scanf("%s", map[i]);
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (map[i][j] == '#' && isLinked(i, j) == 0) {
				f = 0;
			}
		}
	}

	if (f) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}

	return 0;
}

int isLinked(int y, int x)
{
	int ret_value = 0;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny >= 0 && ny < h && nx >= 0 && nx < w &&
				map[ny][nx] == '#') {
			ret_value = 1;
		}
	}

	return ret_value;
}
