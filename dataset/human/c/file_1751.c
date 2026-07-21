#include <stdio.h>

int main(){
	int n,i,j=-2,k,m=0,a[20],b[20],c[20];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		scanf("%d",&b[i]);
	}
	for(i=0;i<n-1;i++){
		scanf("%d",&c[i]);
	}
	for(i=0;i<n;i++){
		k=a[i]-1;
		m+=b[k];
		if(k==j+1){
			m+=c[j];
		}
		j=k;
	}
	printf("%d",m);
	return(0);
}
