#include<stdio.h>
int n,i,j,max[200001],a[200001],m;
int main(void)
{
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	for(i=n-1;i>0;i--) max[i]=0;
	for(i=n-1;i>0;i--){
		if(max[i]<a[i]) max[i]=a[i];
		max[i-1]=max[i];
	}
	m=-1000000000;
	for(i=0;i<n-1;i++){
		if(m<max[i+1]-a[i]) m=max[i+1]-a[i];
	}
	//for(i=0;i<n;i++) printf("AA%d\n",max[i]);
	printf("%d\n",m);
	return 0;
}
