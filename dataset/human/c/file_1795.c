#include<stdio.h>
int main(void){
	int n;
	int a[20], b[20], c[19];
	int sum=0;
	
	scanf("%d",&n);
	
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	
	for(int j=0; j<n; j++){
		scanf("%d", &b[j]);
	}
	
	for(int s=0; s<n-1; s++){
		scanf("%d", &c[s]);
	}
	
	for(int t=0; t<n; t++){
		sum += b[a[t]-1];
		
		if(a[t] - 1 == a[t-1]){
			sum += c[a[t-1]-1];
		}
	}
	
	printf("%d\n", sum);
	
	return 0;
}
