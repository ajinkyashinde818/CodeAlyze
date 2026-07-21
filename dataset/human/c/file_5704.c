#include <stdio.h>
#define M 200000

long int profitsearch(int n, long long int a[]);

int main(void){
	
	long long int a[M];
	int i,n,res;
	scanf("%d",&n);

	for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}

	res=profitsearch(n,a);

	printf("%d\n",res);

	return 0;

}


long int profitsearch(int n,long long int a[]){

	long long int min = 1000000000;
	long long int res, res_max=-2000000001;
	int i;

	for(i=0;i<n;i++){
		if(i>0){
		res = a[i]-min;
		if(res_max<res) res_max=res;
		}
		if(a[i]<min) min = a[i];
	}

	return res_max;

}
