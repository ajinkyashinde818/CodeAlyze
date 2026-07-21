#include<stdio.h>
int main(){

	int k,n,a[200000],i,max=0,shu;

	scanf("%d%d",&k,&n);

	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(i>0){
			if(max<(a[i]-a[i-1]))
				max=a[i]-a[i-1];
		}
	}

	if(max<k+a[0]-a[n-1])
		max=k+a[0]-a[n-1];

	printf("%d",k-max);	

	return 0;
}
