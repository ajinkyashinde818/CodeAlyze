#include <stdio.h>
#include <string.h>

int main(){
	long int i,j,N,K,A[200200];
	long int max_len=-1,max_index,ans;
	scanf("%ld%ld",&K,&N);
	
	for(i=0;i<N;i++){
		scanf("%ld",A+i);
		if(i>0){
			if (max_len<A[i]-A[i-1]){
				max_len = A[i]-A[i-1];
				max_index = i;
			}
		}
	}
	
	if(max_len < A[0]+K-A[N-1]){
		max_len = A[0]+K-A[N-1];
		max_index = 0;
	}
	
	printf("%ld\n",K-max_len);
 return 0;
 }
