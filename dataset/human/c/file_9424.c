#include <stdio.h>


int main(){
	
	int n,a[101],d,x,i,sum=0,j;
	
	scanf("%d\n%d %d",&n,&d,&x);
	
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		for(j=0;j<d;j=j+a[i]){
			sum=sum+1;
		}
	}
	
	printf("%d\n",sum+x);
	
	return 0;
}
