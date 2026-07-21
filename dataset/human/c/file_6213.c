#include<stdio.h>
#include<limits.h>
int main(){
    int N,i,j,Min=INT_MAX,Max=INT_MIN;
	scanf("%d",&N);
	int A[N];
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	/*Max check*/
	for(i=0;i<N;i++){
			if(Max<A[i]-Min)Max=A[i]-Min;
			if(Min>A[i])Min=A[i];
	}
	printf("%d\n",Max);
    return 0;
}
