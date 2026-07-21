#include<stdio.h>
int main()
{
	int i,n,a[200010],ans,min;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	min=a[0];
	ans=a[1]-a[0];
	for(i=1;i<n;i++){
		if(a[i]<min) min=a[i];
		else if(a[i]-min>ans) ans=a[i]-min;
	}
	printf("%d\n",ans);
	return 0;
}
