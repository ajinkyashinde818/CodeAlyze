#include<stdio.h>
#include<string.h>

int i,j,n,c,ans,flag[1000000];

int main(){
	while(scanf("%d",&n)!=EOF){
		if(n==0)break;ans=c=0;
		memset(flag,0,sizeof(int)*1000000);
		for(i=2;i<=1000000;i++){
			if(flag[i]==0){
				for(j=2;j*i<=1000000;j++){
					flag[j*i]=1;
				}
				ans+=i;c++;
			}
			if(n==c)break;
		}
		printf("%d\n",ans);
	}
	return 0;
}
