#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int h, w, a[85][85], b[85][85], grid[85][85][16000], ans;

int min(int x,int y){
	if(x<y)return x;
	else return y;
}

void input(void) {
	scanf("%d%d",&h,&w);
	for (int i = 0; i < h; i++)for (int j = 0; j < w; j++)scanf("%d",&a[i][j]);
	for (int i = 0; i < h; i++)for (int j = 0; j < w; j++)scanf("%d",&b[i][j]);
	ans = 1000000000;
	memset(grid, -1, sizeof grid);
}

void solve(int x, int y, int diff) {
	if (x == h - 1 && y == w - 1) {
		ans = min(ans, abs(diff + (a[x][y] - b[x][y])));
		ans = min(ans, abs(diff - (a[x][y] - b[x][y])));
		return;
	}
	if (x > h || y > w)return;
	if (grid[x][y][diff] != -1)return;
	grid[x][y][diff] = 1;
	solve(x + 1, y, abs(diff + (a[x][y] - b[x][y])));
	solve(x + 1, y, abs(diff - (a[x][y] - b[x][y])));
	solve(x, y + 1, abs(diff + (a[x][y] - b[x][y])));
	solve(x, y + 1, abs(diff - (a[x][y] - b[x][y])));
}

int main() {
	input();
	solve(0, 0, 0);
	printf("%d\n",ans);
	return 0;
}
