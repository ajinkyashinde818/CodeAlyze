#include<stdio.h>
int main()
{
	int n;
	int a[100000];
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int x=1,t=0,flg=0;
	for(int j=1;j<=n;j++){
		x=a[x] ;
		++t;
		if(x==2){
			flg=1;      
			break;
		}
	}
	if(flg)
		printf("%d\n",t); 
	else
		printf("-1");
	return 0;
}
