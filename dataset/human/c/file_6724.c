#include<stdio.h>
int main(){
			int check[501]={0};
		int list[10001][2]={0};
	int n,m,i,j,a,b,ans=0;
	while(1){
		scanf("%d",&n);
		for(i=0;i<=n;i++){
			check[i]=0;
		}
		ans=0;
		check[1]=1;
		scanf("%d",&m);
		if(n==0&&m==0)break;
		for(i=0;i<m;i++){
			scanf("%d%d",&list[i][0],&list[i][1]);
			if(list[i][0]==1){
				ans++;
				check[list[i][1]]=1;
			}
			else if(list[i][1]==1){
				ans++;
				check[list[i][0]]=1;
			}
		}
		for(i=0;i<m;i++){
			if(check[list[i][0]]==1&&check[list[i][1]]==0){
				check[list[i][1]]=2;
				ans++;
			}
			else if(check[list[i][0]]==0&&check[list[i][1]]==1){
				check[list[i][0]]=2;
				ans++;
			}
		}
		/*		for(i=1;i<=n;i++){
			printf("%2d",check[i]);
		}*/
		//printf("\n");
		printf("%d\n",ans);
	}
}
