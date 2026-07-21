#include <stdio.h>

int h, w, diff[80][80];
char dp[80][80][80*(80+80)+1];

int abs (int x) { return x < 0 ? - x : x; }

int main (void) {
	int a, x, y, d, d1, d2;
	
	scanf("%d %d", &h, &w);
	
	for (y = 0; y < h; y++) {
		for(x = 0; x < w; x++) {
			scanf("%d", &diff[x][y]);
		}
	}
	
	for(y = 0; y < h; y++) {
		for(x = 0;x<w;x++)
		{
			scanf("%d", &a);
			diff[x][y] = abs(diff[x][y] - a);
		}
	}
	
	dp[0][0][diff[0][0]] = 1;
	for(y=0;y<h;y++){
		for(x=0;x<w;x++)
		{
			for(d=0;d<=(80+80)*80;d++) {
		  	d1 = abs(d-diff[x][y]);
	  		d2 = abs(d+diff[x][y]);
				if(x>0 && (dp[x-1][y][d1] || dp[x-1][y][d2])) {
					dp[x][y][d] = 1;
					continue;
				}
				if(y>0 && (dp[x][y-1][d1] || dp[x][y-1][d2])) {
					dp[x][y][d] = 1;
				}
			}
		}
	}
	
	for(d=0;!dp[w-1][h-1][d];d++)
	{
	}
	
	printf("%d\n", d);
}
