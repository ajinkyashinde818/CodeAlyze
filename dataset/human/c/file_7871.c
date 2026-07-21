#include<stdio.h>
char c[5000][5000];
int x[5000];
int ans[5000];
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	bool ok=false;
	for(int i=0;i<b;i++){
		int d,e;
		scanf("%d%d",&d,&e);
		d--;e--;
		c[d][e]=1;
		c[e][d]=2;
		x[e]++;
	}
	for(int i=0;i<a;i++){
		int v=0;
		int at=0;
		for(int j=0;j<a;j++){
			if(x[j]==0){
				at=j;
				v++;
			}
		}
		if(v>1)ok=true;
		x[at]=99999999;
		ans[i]=at;
		for(int j=0;j<a;j++)if(c[j][at]==2)x[j]--;
	}
	for(int i=0;i<a;i++)printf("%d\n",ans[i]+1);
	if(ok)printf("1\n");
	else printf("0\n");
}
