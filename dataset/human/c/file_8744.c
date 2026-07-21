#include<stdio.h>
#define N 100000+10
int main()
{
	int a[N];
	int n;
	int sum=0;
	int flag=1;
	int flag2=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==2)
			flag2++;
	}
	if(flag2==0)
		printf("-1");
	else {
		int i=1;
		while(a[i]!=2){
			if(a[a[i]]==i||i==a[i]||sum+1>n){
				flag=0;break;
			}
				
			i=a[i];
			sum++;
			
		}
		if(flag==0)
			printf("-1");
		else 
			printf("%d",sum+1);
	}
}
