#include<stdio.h>
#include<stdlib.h>
long a[300000];

int cmp(const void *a,const void *b){
	return *(long*)b-*(long*)a;
}

int main(int argc, char const *argv[]){
	long n,i;
	long long ans=0;
	scanf("%ld",&n);
	for(i=0;i<3*n;i++){
		scanf("%ld",&a[i]);
	}
	qsort(a,3*n,sizeof(long),cmp);
	for(i=0;i<n;i++){
		ans+=(long long)a[i*2+1];
	}
	printf("%lld\n",ans);
	return 0;
}
