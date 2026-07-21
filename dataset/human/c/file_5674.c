#include<stdio.h>

#define N 200000


int main(void){

	int n;
	int A[N],max,min,value;
	
	scanf("%d",&n);
	
	for(int i = 0;i<n;i++){
		
		scanf("%d",&A[i]);
	}
	
	
	min =A[0];
	max=A[1]-A[0];
	
	for(int i=1;i<n;i++){
		
	value = A[i] - min;
	if(max<value){max=value;}
	if(min>A[i]){min = A[i];}
		
		
	}
	
	printf("%d\n",max);
	
	return 0;
	}
