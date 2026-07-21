#include <stdio.h>
int main(){
	int n,sum = 0, i;
	scanf("%d", &n);
	int a[n],b[n],c[n-1];
	for(i=0;i<n;++i){
		scanf("%d", &a[i]);
	}
	for(i=0;i < n;++i){
		scanf("%d", &b[i]);
	}
	for(i=0;i < n-1 ;++i){
		scanf("%d", &c[i]);
	}
	for(i=0; i < n;++i){
		if ((i != 0) && (a[i] == a[i-1]+1)){
			sum += c[a[i-1]-1];
		}
		sum += b[a[i]-1];
	}
	printf("%d\n", sum);
	return 0;
}
