#include<stdio.h>
int main()
{
   

    int N;
  
    scanf("%d", &N);
  	int A[N];
  	int B[N];
  	int C[N-1];
  
  	int i=0;
  for(i=0;i<N;i++){
	scanf("%d", &A[i]);
  }
  
  int sum = 0;
   for(i=0;i<N;i++){
	scanf("%d", &B[i]);
     sum = sum + B[i];
    // printf("sum%d",sum);
  }
   int ch[N-1];
   for(i=0;i<N-1;i++){
	scanf("%d", &C[i]);
     ch[i] = 0;
  }
 
     for(i=0;i<N-1;i++){
	if(A[i] == A[i+1]-1){
      ch[A[i]-1] = 1;
   //   printf("i:%d",i);
    }
  }
  
  for(i=0;i<N-1;i++){
	if(ch[i] == 1){
     // printf("i:%d",i);
		sum = sum +C[i];
      //printf("sum:%d",sum);
    }
  }
  
  
  
 
    printf("%d",sum);//printf("%c",s[0])//文字一つ分のみを出力

    return 0;
}
