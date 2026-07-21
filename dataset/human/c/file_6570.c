#include<stdio.h>
#define N 200000
int main(){
	int n,i,j,max,min;
	int a[N];
	scanf("%d",&n);
	//scanf("%d",&a[0]);
	
	for(i = 0; i < n; i++){
		scanf("%d",&a[i]);
		//max = mac(max,a[i - 1],a[i]);
	}
	min = a[0];
	max = a[1] - a[0];
	for(i = 1; i < n; i++){
    	if(max < a[i] - min) max = a[i] - min;
    	if(min > a[i]) min = a[i];
  	}
	printf("%d\n",max);

	return 0;
}
