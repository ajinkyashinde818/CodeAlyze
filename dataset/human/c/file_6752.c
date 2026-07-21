#include<stdio.h>
#include<string.h>
int main(){
	int i,j,n,m,a,b,ans;
	int f[505][505],c[505],d[505];
	while(1){
		scanf("%d",&n);
		if(n==0)break;
		scanf("%d",&m);ans=0;
		memset(f,0,sizeof(f));
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d));
		for(i=0;i<m;i++){
			scanf("%d%d",&a,&b);
			f[a][c[a]]=b;
			f[b][c[b]]=a;
			c[a]++;c[b]++;
		}
		/*for(i=1;i<=n;i++){
			printf("%d:",i);
			for(j=0;j<c[i];j++)printf("%d ",f[i][j]);
			printf("\n");
		}*/
		for(i=0;i<c[1];i++){
			if(f[1][i]!=1 && d[f[1][i]]==0)
				d[f[1][i]]=1,ans++;
			for(j=0;j<c[f[1][i]];j++){
				if(f[f[1][i]][j]!=1 && d[f[f[1][i]][j]]==0){
					d[f[f[1][i]][j]]=1;
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
