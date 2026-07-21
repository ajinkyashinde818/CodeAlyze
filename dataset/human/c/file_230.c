#include<stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
	int n, i, j, min;
	long long abs_t;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	abs_t = 0;
	int count = 0;
	min = abs(a[0]);
	for(i=0;i<n;i++){
		abs_t += abs(a[i]);
		if(a[i]<0){
			count++;
		}
		if(min>abs(a[i]))min=abs(a[i]);
	}
	
	if(count%2==1){
		printf("%lld",abs_t-min*2);
	}else{
		printf("%lld",abs_t);
	}
	
	
	return 0;
}
