#include<stdio.h>
#include<stdlib.h>

int sortfnc(const void *a,const void *b){
    if(*(long long*)a == *(long long*)b){return 0;}
    if(*(long long*)a > *(long long*)b){return -1;}
    return 1;
}

int main(void){
	long long n,a[524288],r = 0,i;
	scanf("%lld",&n);
	for(i = 0;i < 3*n;i++){scanf("%lld",&a[i]);}
	qsort(a,3*n,sizeof(long long),sortfnc);
	for(i = 1;i < 2*n;i+=2){r+=a[i];}
	printf("%lld\n",r);
	return 0;
}
