#include <stdio.h>
#define N_MAX 1000

int w,h;
int n, xy[N_MAX][2];

int sgn(int n){
	if(n<0)
		return -1;
	if(n>0)
		return 1;
	return 0;
}

int abs(int n){
	return(n>0)?n:-n;
}

int difference(int x,int y){
	return abs(x-y);
}

int min(int x,int y){
	return (x<y)?x:y;
}

int path(int x, int y){
	int ans = difference(x,y);
	if(sgn(x)==sgn(y))
		ans += min(abs(x),abs(y));
	return ans;
}

void solve(void){
	int answer = 0;
	int i = 0;
	while(++i < n){
		int
		x = xy[i][0] - xy[i-1][0],
		y = xy[i][1] - xy[i-1][1];
		answer += path(x,y);
	}
	printf("%d\n",answer);
	return;
}

int main(void){
	int i;
	scanf("%d%d%d",&w,&h,&n);
	for(i=0;i<n;i++){
		scanf("%d%d", &xy[i][0], &xy[i][1]);
	}
	solve();
	return 0;
}
