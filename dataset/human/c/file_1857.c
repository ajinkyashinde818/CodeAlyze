#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main(){
	int n;
	scanf("%d", &n);
	int a[n], b[n], c[n];
	int sat=0;
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	for(int i=0; i<n; i++){
		scanf("%d", &b[i]);
		sat+= b[i];
	}
	for(int i=0; i<n-1; i++){
		scanf("%d", &c[i]);
	}
	
	//printf("%d\n", sat);//jijiji
	
	for(int i=1; i<n; i++){
		if(a[i]-a[i-1]==1){
			sat+= c[a[i-1]-1];
			//printf("%d:%d\n", i, sat);//jijiji
		}
	}
	
	printf("%d\n", sat);
	
	
	return 0;
}
