#include<stdio.h>
int main(void){
	
	int n;
	scanf("%d",&n);
	int a[n];
	
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	int maxv=a[1]-a[0];
	int minv=a[0];
	
	for(int j=1;j<=n-1;j++){
		if(maxv<a[j]-minv){
			maxv=a[j]-minv;
		}
		if(minv>a[j]){
			minv=a[j];
		}
	}
	
	
	
	printf("%d",maxv);
	printf("\n");
	return 0;
}
