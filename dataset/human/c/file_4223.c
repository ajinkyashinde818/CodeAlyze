#include<stdio.h>

int main(void)
{
	long long int n,i,m,ans,a1=1,a2=2,a3;
	int a[100001]={0};
	int temp;
	
	scanf("%lld%lld",&n,&m);
	
	for(i=1;i<=m;i++){
		scanf("%d",&temp);
		a[temp]=1;
		}
		
	if(a[1]==1){
		a1=0;
		a2=1;
		}
	if(a[2]==1)
		a2=0;
	if(n==1){
		printf("1");
		return 0;
		}
	if(n==2){
		printf("%d",a2);
		return 0;
		}

	for(i=0;i<n-2;i++){
		a3=a1+a2;
		if(a[3+i]==1)
			a3=0;
		a1=a2%1000000007;
		a2=a3%1000000007;
	}
		
	ans=a3%1000000007;
	printf("%lld",ans);
	return 0;
}
