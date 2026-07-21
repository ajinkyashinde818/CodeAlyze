#include<stdio.h>
int main(){
	int n,i,min,range,R[200000];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&R[i]);
	}
	min=R[0];
	range=R[1]-R[0];
	for(i=1;i<n;i++){
		if(range<R[i]-min){
			range=R[i]-min;
		}
		if(min>R[i]){
			min=R[i];
		}
	}
	printf("%d\n",range);
	return 0;
}
