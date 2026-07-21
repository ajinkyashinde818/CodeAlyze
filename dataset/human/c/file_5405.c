#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.141592653589793
#define MOD 1000000007

//qsort用、昇順
int compare_int(const void *a, const void *b)
{
	return *(int*)a-*(int*)b;
}
//qsort(data, 10, sizeof(int), compare_int)

int n, m, x;
int c[15], a[15][15];
int min, nowa[15];

void dfs(int i, int summ){
	//printf("i:%d, summ:%d, min:%d\n", i, summ, min);
	if(i==n){
		int chk=1;
		for(int j=0; j<m; j++){
			if(nowa[j]<x) chk=-1;
		}
		if((chk>0) && (min>summ)){
			min = summ;
		}
	}
	else{
		dfs(i+1, summ);
		for(int j=0; j<m; j++){
			nowa[j] += a[i][j];
		}
		dfs(i+1, summ+c[i]);
		for(int j=0; j<m; j++){
			nowa[j] -= a[i][j];
		}
	}
	
}

int main(){
	scanf("%d%d%d", &n, &m, &x);
	for(int i=0; i<n; i++){
		scanf("%d", &c[i]);
		for(int j=0; j<m; j++){
			scanf("%d", &a[i][j]);
		}
	}

	min = 10000000;
	for(int i=0; i<n; i++){
		nowa[i] = 0;
	}
	dfs(0, 0);
	if(min == 10000000) printf("-1\n");
	else printf("%d\n", min);
	
	return 0;
}
