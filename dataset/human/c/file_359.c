#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define roop(p,q) for(p=1;p<=q;q++)

int main(){

 long long int N,M;
  scanf("%lld %lld",&N,&M);

/*
  char A[];
  scanf("%s",A);
  */

 /* 
  long long int A[N+1];
  long long int i;
  for(i=1;i<=N;i++){
   scanf("%lld",&A[i]);
   }
  */
  
if(N>=10){
  printf("%lld",M);
}
else{
  printf("%lld",M+100*(10-N));
}








 return(0);
 }
