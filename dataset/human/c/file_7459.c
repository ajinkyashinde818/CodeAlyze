#include <stdio.h>
int main(){
	int a[1000000];
	int n,i;
	n=0;
	do{
		n=n+1;
		scanf("%d",&a[n]);
	}while(a[n]!=0);
	
	for(i=1;i<n;i++){
		printf("Case %d: %d\n",i,a[i]);
	}
return 0;
}
