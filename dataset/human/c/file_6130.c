#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main(){
  int n;
  int i;
  int Ans;
  int Max,Min;
  int *A;
  int *R;
  
  scanf("%d",&n);
  A=malloc(n*sizeof(int));
  for(i=0;i<n;i++) scanf("%d",&A[i]);
  
  Max=A[0];
  Min=A[0];
  Ans=A[1]-A[0];
  for(i=1;i<n;i++){
    if(Max < A[i]) Max=A[i];
    if(Min > A[i]){
      Min=A[i];
      if(i+1!=n) Max=A[i+1];
      else Max=-999999999;
    }
    if(Ans < Max-Min) Ans = Max-Min;
  }
  printf("%d\n",Ans);
  return 0;
}
