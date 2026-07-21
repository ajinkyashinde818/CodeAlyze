#include<stdio.h>
int main(void)
{
	int a[100],n,k,p,i,j,cnt;
	cnt=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d",&k,&p);
		if(k%p==0){
			a[i]=p;
		}
		else {
			a[i]=k%p;
		}
	}
	for(j=0;j<n;j++){
		printf("%d\n",a[j]);
	}
	return 0;
}
