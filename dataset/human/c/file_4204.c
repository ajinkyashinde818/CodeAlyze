#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#include<float.h>

#define NUM 100001

int step(int n, int i, int m, int *ans){
	if(i==-1) return 0;
	else if (i==0) return 1;
	else if (ans[i] != -1) return ans[i];
	else return ans[i] = (step(n, i - 1, m, ans) + step(n, i - 2, m, ans)) % 1000000007;
}

int main(){
	int n, m, ans[NUM], a;
	scanf("%d%d\n", &n, &m);
	for(int i=0; i<n+1; i++){
		ans[i] = -1;
	}
	for(int i=0; i<m; i++){
		scanf("%d", &a);
		ans[a] = 0;
	}
	printf("%d\n", step(n, n, m, ans));
	return 0;
}
