#include<stdio.h>
int main(void)
{
	int n,m,k,i,j,a[101],temp;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	k=1;
	while(1){
		for(i=0;i<n-1;i++){
			if(a[i]%k>a[i+1]%k){
				temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
			}
		}
		if(k==m)break;
		k++;
	}
	for(i=0;i<n;i++){
		printf("%d\n",a[i]);
	}
	return 0;
}
