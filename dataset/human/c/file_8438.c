#include<stdio.h>
int main(void)
{
    int n,m,a[100],i,w,j,z,x;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){
	    scanf("%d",&a[i]);
	}
	for(i=1;i<=m;i++){
	    for(j=0;j<n-1;j++){
			if(a[j]%i>a[j+1]%i){
			    w=a[j];
				a[j]=a[j+1];
				a[j+1]=w;
			}
		}
	}
	for(i=0;i<n;i++){
	    printf("%d\n",a[i]);
	}
	return 0;
}
