#include <stdio.h>

int main(){
	int n;
	scanf("%d",&n);
	
	int a[n];
	int b[n];
	int c[n-1];
	
	for(int i=0; i<n; i++){
		scanf("%d",&a[i]);
	}
	for(int i=0; i<n; i++){
		scanf("%d",&b[i]);
	}
	for(int i=0; i<n-1; i++){
		scanf("%d",&c[i]);
	}
	
	int manzoku=0;

	
	for(int i=0; i<n; i++){
		manzoku += b[a[i]-1]; 
		if(i>0&&a[i]==a[i-1]+1){
			manzoku += c[a[i-1]-1]; 
		}
	}
	
	printf("%d",manzoku);
}
