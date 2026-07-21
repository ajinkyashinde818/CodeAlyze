#include <stdio.h>
#include <stdlib.h>
int comp(const void *a, const void *b){
	long long int *A=(long long int *)a;
	long long int *B=(long long int *)b;
	if(*A>*B){
		return -1;
	}
	return 1;
}
int main(){
	long long int N;
	long long int a[300000];
	scanf("%lld",&N);
	int i;
	for(i=0;i<3*N;i++){
		scanf("%lld",&a[i]);
	}
	qsort(a,3*N,sizeof(long long int),comp);
	long long int ans;
	ans=0;
	for(i=1;i<2*N;i=i+2){
		ans=ans+a[i];
	}
	printf("%lld",ans);
}
