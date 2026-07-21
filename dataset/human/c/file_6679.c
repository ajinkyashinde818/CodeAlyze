#include <stdio.h>

void fx(int A[],int m);
int main (void){
	int m;
	scanf("%d",&m);
	int A[m];
	for(int i=0;i<m;i++){
		scanf("%d",&A[i]);
	}
	fx(A,m);
}

void fx(int A[],int m){

	int min,max;
	min=A[0];
	max=A[1]-A[0];
	for(int j=1;j<=m-1;j++){
		if(A[j]-min>max){
			max=A[j]-min;
		}
		
		if(A[j]<min){
			min=A[j];
		}
	}
	
	printf("%d\n",max);
}
