#include<stdio.h>

int main(){
	int K,N;
  	scanf("%d %d",&K,&N);
  
  	int A[N],ans=0,sum=0,max=0;
  	for(int i=0;i<N;i++){
	  	scanf("%d",&A[i]);
      if(i>0){		
      	sum += A[i] - A[i-1];
      }
      if(max<(A[i]-A[i-1])){
      	max = A[i] - A[i-1];
      }
    }
  	int lest=0;
    lest = K-sum;
  	
  	if(lest > max){
        max = lest;
    	ans = sum + lest - max;
    }else{
    	ans = sum + lest - max;
    }
    
  	printf("%d",ans);  	  	  	
	return 0;
}
