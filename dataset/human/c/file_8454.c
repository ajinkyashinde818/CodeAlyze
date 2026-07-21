#include<stdio.h>

int A[110];
int main(){
  int N,M,i,j,t;
  scanf("%d%d",&N,&M);
  for(i=0;i<N;i++) scanf("%d",A+i);
  for(i=1;i<=M;i++){
    for(j=0;j<N-1;j++){
      if(A[j]%i>A[j+1]%i){
	t=A[j];
	A[j]=A[j+1];
	A[j+1]=t;
      }
    }
  }
  for(i=0;i<N;i++) printf("%d\n",A[i]);
  return 0;
}
