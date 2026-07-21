#include<stdio.h>
int main(){
	int ans,list[10001][2],num[501],n,k,i,j;
	while(1){
		scanf("%d%d",&n,&k);
		if(n==0 && k==0)break;
		for(i=0;i<n;i++)num[i]=0;
		for(i=0;i<k;i++){
			scanf("%d%d",&list[i][0],&list[i][1]);
			if(list[i][0]==1)num[list[i][1]-1]=1;
		}
		for(i=0;i<n;i++){
			if(num[i]==1){
				for(j=1;j<k;j++){
					if(num[list[j][0]-1]==1 && num[list[j][1]-1]==0)num[list[j][1]-1]=2;
					if(num[list[j][1]-1]==1 && num[list[j][0]-1]==0)num[list[j][0]-1]=2;
				}
			}
		}
		num[0]=0;
		ans=0;
		for(i=0;i<n;i++){
			if(num[i]!=0)++ans;
		}
		printf("%d\n",ans);
	}
	return 0;
}
