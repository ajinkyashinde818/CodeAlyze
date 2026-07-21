#include<stdio.h>

void read(int *n,int A[]){
	scanf("%d",n);
	int i;
	for (i = 0; i < *n; i++) {
		scanf("%d", &A[i]);
	}
}

void profitchange(int *profit,int *max,int *min){
	if(*profit<*max-*min){
		*profit = *max - *min;
	}
}

int getprofit(int n,int A[]){
	int i,profit,max,min;
	profit = A[1]-A[0];
	max=min=A[0];
	for(i=0;i<n;i++){
		if(A[i]<min){
			max=min=A[i];
		}else if(A[i]>max){
			max = A[i];
			profitchange(&profit,&max,&min);
		}else if(A[i]==A[i-1]){
			profitchange(&profit,&max,&min);
		}
	}

	return profit;
}

int main(){
	int n,A[200000];
	read(&n,A);
	printf("%d\n",getprofit(n,A));

	return 0;
}
