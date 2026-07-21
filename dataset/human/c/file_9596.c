#include <stdio.h>

void init(int A[],int N);

int main(){
  int N,D,X;
  int A[100];
  int i;
  int ct=0;

  scanf("%d%d%d",&N,&D,&X);
  init(A,N);

  for(i=0;i<N;i++){
    ct+=D/A[i];
    if(D%A[i]){
      ct++;
    }
  }
  printf("\n%d\n",ct+X);

  return 0;
}
void init(int A[],int N){
  for(int i=0;i<N;i++)scanf("%d",&A[i]);
}
