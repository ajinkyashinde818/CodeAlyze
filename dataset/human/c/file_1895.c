#include<stdio.h>

int main()
{
	int n;
	int i;
	scanf("%d", &n);
	int a[n+1],b[n+1],c[n];
	int pre=-1;
	int manzoku=0;

	for(i=1;i<n+1;i++)
		scanf("%d",&a[i]);
	for(i=1;i<n+1;i++)
		scanf("%d",&b[i]);
	for(i=1;i<n;i++)
		scanf("%d",&c[i]);
	for(i=1;i<=n;i++){
		if(pre+1==a[i]){
			manzoku+=c[pre];
		}
		manzoku+=b[a[i]];
		pre=a[i];
	}
	printf("%d\n",manzoku);
	return 0;

}
