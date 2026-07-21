#include<stdio.h>

int main(){
  int N,i;
  scanf("%d",&N);
  int A[N];

  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  int minv = A[0],maxv = A[1]-A[0];

  for(i=1;i<N;i++){
    if(maxv < A[i]-minv){
      maxv = A[i]-minv;
    }else{
      maxv = maxv;
    }
    if(minv < A[i]){
      minv = minv;
    }else{
      minv = A[i];
    }
  }

  printf("%d\n",maxv);
  return 0;
}
