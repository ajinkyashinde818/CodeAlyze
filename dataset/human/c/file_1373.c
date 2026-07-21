#include<stdio.h>

//数组a和b存储连接线，数组c存储岛屿。
int a[200001],b[200001],c[200001];

int main(void)
{
	int n,m,possible;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) c[i]=0;
	//和1相连的岛屿都打上标记。
	for(int i=0;i<m;i++) scanf("%d %d",&a[i],&b[i]);
	for(int i=0;i<m;i++){
		if(a[i]==1) c[b[i]]=1;
	}
	//再次遍历m条线，起点打过标记同时终点是n,则为possible。
	possible=0;
	for(int i=0;i<m;i++){
		if(c[a[i]]==1&&b[i]==n){
			possible=1; 
			break;
		}
	}	
	if(possible) printf("POSSIBLE\n");
	else printf("IMPOSSIBLE\n");
	return 0;
}
