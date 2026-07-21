#include <stdio.h>
#include <limits.h>

#define REP(i,n,m) for(i=n;i<m;i++)
#define rep(i,n) REP(i,0,n)

int isCorrect(int n,int m,int w,int *t){
	int i, now = 0;

	rep(i,n){
		int sum = 0;
		for(;now<m && sum+t[now]<=w;sum+=t[now],now++);
		if(now == m) return 1;
	}

	return 0;
}

int getMin(int sp,int m,int *t){
	int left=0,right=0,sum=0;
	int res = INT_MAX;

	for(;left<m;left++){
		if(left != 0) sum -= t[left-1];
		for(;right<m && sum<=sp;sum+=t[right],right++);
		if(sp < sum && sum < res) res = sum;
	}

	return res;
}

int main(void){
	int i,j,start,end;
	int n,m;
	int w,t[100];

	while(scanf("%d%d",&n,&m) && (n||m)){
		rep(i,m) scanf("%d",&t[i]);

		w = 0;
		rep(i,m) if(w < t[i]) w = t[i];
		while(1){
			if(isCorrect(n,m,w,t)) break;
			w = getMin(w,m,t);
		}
		printf("%d\n",w);
	}

	return 0;
}
