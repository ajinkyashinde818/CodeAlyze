#include<stdio.h>

int main(){
	int n,m,i,a,b,temp[2][200001]={0};
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		if(a==n){
			temp[1][b]=1;
		}
		if(b==n){
			temp[1][a]=1;
		}
		if(a==1){
			temp[0][b]=1;
		}
		if(b==1){
			temp[0][a]=1;
		}
	}
	for(i=0;i<=200000;i++){
		if(temp[0][i]==1&&temp[1][i]==1){
				puts("POSSIBLE");
				return 0;
		}
	}
	puts("IMPOSSIBLE");
	return 0;
}
