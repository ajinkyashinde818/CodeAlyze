#include <stdio.h>

int main(void) {
	int i,n,t,j,w;
	t=0;
	scanf("%d",&n);
	int a[n],b[n],c[n-1];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		scanf("%d",&b[i]);
		t+=b[i];
	}
	for(i=0;i<n-1;i++){
		scanf("%d",&c[i]);
	}
	for(i=0;i<n-1;i++){
		j=i+1;
		if(a[i]+1==a[j]){
			w=a[i]-1;
			t+=c[w];
		}
	}
	printf("%d",t);
	
	
	
	// your code goes here
	return 0;
}
