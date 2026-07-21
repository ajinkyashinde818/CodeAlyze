#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX(a,b) ( (a)>(b) ? (a) : (b) )

int i,j,k,n,m,cases[50][150],wid,www;

int main(){
	while(scanf("%d %d",&m,&n)*m*n){
	for(i=1;i<=n;i++){
		scanf("%d",&cases[1][i]);
		cases[1][i]+=cases[1][i-1];
	}

	for(i=2;i<=m;i++){
		for(j=1;j<=n;j++){
			wid=9999999;
			for(k=1;k<=j;k++){
				www=MAX(cases[i-1][k],cases[1][j]-cases[1][k]);
				if(www<wid)wid=www;
			}
			cases[i][j]=wid;
		}
	}

	printf("%d\n",cases[m][n]);

	}
	return 0;
}
