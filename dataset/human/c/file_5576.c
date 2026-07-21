#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include<string.h>

int main(){
	
	int n,num[200000]={0};
	int i,j,sum=0,ans[10000]={0};
	
	while(scanf("%d",&n)!=EOF){
		if(n==0)break;
	for(i=2;i<=110000;i++)num[i]=i;
	
	for(i=2;i<=sqrt(110000);i++){
		for(j=2;j*i<=110000;j++)num[i*j]=0;
	}
	
	for(i=0,j=0;i<=110000;i++){
		if(num[i]!=0){
			ans[j]=num[i];
			j++;
		}
		if(n==j)break;
	}
	for(i=0;i<j;i++)sum+=ans[i];
	
	printf("%d\n",sum);
		
		sum=0;
	}
return 0;
}
