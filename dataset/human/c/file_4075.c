#include<stdio.h>
int main(void)
{
	int a,b,k,cnt=0,ans=0,i;
	scanf("%d %d %d",&a,&b,&k);
	for(i=100;i>=1;i--){
		if(a%i==0 && b%i==0){
			cnt=cnt+1;
			ans=i;
		}
		if(cnt==k){
			break;
		}
	}
	printf("%d\n",ans);
	return 0;
}
