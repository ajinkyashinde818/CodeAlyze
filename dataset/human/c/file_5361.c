#include<stdio.h>
int n,m,x,min=1000000007;
int book[105][105],learn[105];
void make(int i,int fall,int money){
	if(fall==m){
		if(money<min) min=money;
		return ;
	}
	if(i==n+1) return ;
	make(i+1,fall,money);
	int f[105];
	for(int j=1;j<=m;j++) f[j]=learn[j];
	for(int j=1;j<=m;j++){
		if(learn[j]>=x) continue; 
		learn[j]+=book[i][j];
		if(learn[j]>=x) fall++;
	}
	money+=book[i][m+1];
	make(i+1,fall,money);
	for(int j=1;j<=m;j++) learn[j]=f[j];
}
int main(){
	scanf("%d%d%d",&n,&m,&x);
	for(int i=1;i<=n;i++){
		scanf("%d",&book[i][m+1]);
		for(int j=1;j<=m;j++) scanf("%d",&book[i][j]);
	}
	make(1,0,0);
	printf("%d",min!=1000000007?min:-1);
	return 0;
}
