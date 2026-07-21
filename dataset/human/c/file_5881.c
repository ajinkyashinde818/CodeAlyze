#include<stdio.h>
int main(void){
	int N,i,j,ans,max,min,flag=0;
	scanf("%d",&N);
	int A[N];
	for(i=0;i<N;i++){
		scanf("%d",A+i);
	}
	min = A[0];
	for(i=1;i<N;i++){
		ans = A[i]-min;
		if(flag==0){
			max = ans;
			flag=1;
		}
		if(max < ans) max = ans;
		if(min > A[i]) min = A[i];
	}
	printf("%d\n",max);
	return 0;
}
