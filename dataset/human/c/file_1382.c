#include <stdio.h>

int c[2000001];
int d[2000001];
int main(void){
	int N,M;
	scanf("%d%d",&N,&M);
	int i,j;
	int a[M],b[M];
	int ccount = 0,dcount=0;
	for(i=0;i<M;i++){
		scanf("%d%d",&a[i],&b[i]);
		//1からいける島をc[i]に保存する
		//Nからいける島をd[i]に保存する
		if(a[i]==1)c[b[i]]=1;
		if(b[i]==N)d[a[i]]=1;
	}
	for(i=1;i<=N;i++){
		if(c[i]==d[i]&&c[i]==1){
			printf("POSSIBLE");
			return 0;
		}
	}
	printf("IMPOSSIBLE");
	return 0;
}
