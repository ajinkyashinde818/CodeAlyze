#include<stdio.h>

int main(){


int n;
scanf("%d",&n);
long long arr[200000] = {0};
scanf("%lli %lli",&arr[0],&arr[1]);
long long min = arr[0];
long long dif = arr[1] - arr[0];
long long max = dif;
for(int i=2;i<n;i++){
	scanf("%lli",&arr[i]);
}
for(int i=1;i<n;i++){

	if(min>arr[i-1])
	min = arr[i-1];

	dif = arr[i] - min;
	if(dif>max)
	max = dif;
}
printf("%lli\n",max);






	return 0;
}
