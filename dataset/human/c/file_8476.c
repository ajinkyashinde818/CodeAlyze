#include<stdio.h>
int main(void)
{
	int n,m,a[101],k,i,j,x,y,z;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;i<=m;i++){
		for(j=1;j<n;j++){
			y=a[j]%i; z=a[j+1]%i;
			if(y>z){
				x=a[j];
				a[j]=a[j+1];
				a[j+1]=x;
			}
		}
	}
	for(i=1;i<=n;i++){
		printf("%d\n",a[i]);
	}
	return 0;
}
