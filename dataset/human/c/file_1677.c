#include<stdio.h>
int main()
{
	int n,a[21],b[21],c[21],i,x,y;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	for(i=1;i<=n-1;i++){
		scanf("%d",&c[i]);
	}
	x=0;
	for(i=1;i<=n;i++){
		x+=b[a[i]];
		if(a[i]+1==a[i+1]){
			x+=c[a[i]];
		}
	}
	printf("%d\n",x);
	return 0;
}
