#include<stdio.h>
int main()
{
	int n,a[21],b[21],c[20],i,m=0;

	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
		scanf("%d",&b[i]);
	for(i=0;i<n-1;i++)
		scanf("%d",&c[i]);
	for(i=0;i<n;i++){
		m+=b[a[i]-1];
		if((i>0)&&(a[i]==a[i-1]+1))
			m+=c[a[i-1]-1];
	}
	//m+=b[a[n-1]-1];
	printf("%d\n",m);
	return 0;
}
