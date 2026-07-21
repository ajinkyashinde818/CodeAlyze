#include<stdio.h>
#define N 200000
#define O 0
#define I 1

int main(){
  int i,n,Min,Max,R[N];

  scanf("%d",&n);
  for(i=O;i<n;i++){
    scanf("%d",&R[i]);
  }
  Min=R[O];
  Max=R[I]-R[O];

  for(i=I;i<n;i++){
    if(Max<R[i]-Min){
      Max=R[i]-Min;
    }
    if(Min>R[i]){
      Min=R[i];
    }
  }

  printf("%d\n",Max);

  return O;
}
