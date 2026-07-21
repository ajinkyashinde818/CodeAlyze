#include <stdio.h>

char dx[] = {-1,0,-1};
char dy[] = {-1,-1,0};
char g[1001][1001];

int main(){
	char m[1001][1001], c[3];
	int n, min, max;

	while(1){
		scanf("%d", &n);
		if(n==0) break;
		max = 0;
		
		for(int i=0 ; i<n ; i++){
			scanf("%s", g[i]);
		}
		
		for ( int i = 0; i < n; i++ ) {
			m[0][i] = (g[0][i] == '*') ? 0 : 1;
			m[i][0] = (g[i][0] == '*') ? 0 : 1;
		}
		for(int y=1 ; y<n ; y++){
			for(int x=1 ; x<n ; x++){
				if( g[y][x] == '*' ){
					m[y][x] = 0;
				}
				else{
					min = 1000;
					for(int i=0 ; i<3 ; i++){
						int mx = x + dx[i];
						int my = y + dy[i];
						c[i] = m[my][mx];
					}
					for(int i=0 ; i<3 ; i++){
						if(c[i]<min) min = c[i];
					}
					m[y][x] = min + 1;
					if(max<m[y][x]) max = m[y][x];
				}
			}
		}
		printf("%d\n", max);
	}
	
	return 0;
}
