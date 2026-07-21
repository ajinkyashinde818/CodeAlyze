#include <stdio.h>

int main()
{
	int i,j,n,max=-2000000000;
	
	scanf("%d",&n);
	
	int a[n],min[n],mi=1000000000;
	
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(i==0){
			mi=a[i];
		}
		
		if(mi>a[i]){
			min[i]=a[i];
			mi=a[i];
		}else{
			min[i]=mi;
		}
	}
	
	for(i=0;i<n-1;i++){
		if(max<a[i+1]-min[i]){
			max=a[i+1]-min[i];
		}
	}
	
	printf("%d\n",max);
	
}
