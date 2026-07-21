#include<stdio.h>
#include<string.h>
char kan[501][501],gou[501];
int main(void){
	int n,m,i,j,sas,a,b;

	while(1){
		scanf("%d%d",&n,&m);
		if(!n && !m)break;
		memset(kan,0,sizeof(kan));
		memset(gou,0,sizeof(gou));
		for(i=0;i<m;i++){
			scanf("%d%d",&a,&b);
			kan[a][b]=kan[b][a]=1;
		}
		for(i=2;i<=n;i++){
			if(kan[1][i]==1){
				gou[i]=1;
				for(j=1;j<=n;j++){
					if(kan[i][j]==1)gou[j]=1;
				}
			}
		}
		sas=0;
		for(i=2;i<=n;i++){
			if(gou[i]==1)sas++;
		}
		printf("%d\n",sas);
	}
	return 0;
}
