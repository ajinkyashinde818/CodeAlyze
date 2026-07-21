#include<stdio.h>
int prt[100010];
bool vit[100010];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&prt[i]);
	}
	int u=1,cnt=0;
	while(1){
		if(u==2){
			printf("%d\n",cnt);
			return 0;
		}
		if(vit[u]){
			printf("-1\n");
			return 0;
		}
		vit[u]=true;
		cnt++;
		u=prt[u];
	}
	return 0;
}
