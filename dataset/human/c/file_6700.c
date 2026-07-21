#include<stdio.h>
bool table[500][500];
int f[500];
int main(){
	int a,b;
	while(scanf("%d%d",&a,&b),a){
		for(int i=0;i<a;i++)for(int j=0;j<a;j++)table[i][j]=false;
		for(int i=0;i<a;i++)f[i]=0;
		for(int i=0;i<b;i++){
			int c,d;
			scanf("%d%d",&c,&d);
			table[c-1][d-1]=true;
			table[d-1][c-1]=true;
		}
		for(int i=1;i<a;i++){
			if(table[0][i])f[i]=1;
		//	printf("%d ",f[i]);
		}
		for(int i=0;i<a;i++){
			if(f[i]==1){
				for(int j=0;j<a;j++)if(table[i][j]&&f[j]==0)f[j]=2;
			}
		}
		int ret=0;
		for(int i=0;i<a;i++)if(f[i])ret++;
		if(ret>0)printf("%d\n",ret-1);
		else printf("0\n");
	}
}
