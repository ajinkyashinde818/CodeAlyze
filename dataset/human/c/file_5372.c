#include <stdio.h>

int N,M,X;
int C[20],A[20][20],D[20];
int min_S=-1;

void f(int p,int S){
  int c=1;
  for(int i=1;i<=M;i++){
    if(D[i]<X) c=0;
  }
  if(c==1){
    if(min_S<0 || S<min_S){
      min_S=S;
      return;
    }
  }
  for(int i=p+1;i<=N;i++){
    for(int j=1;j<=M;j++){
      D[j]+=A[i][j];
    }
    f(i,S+C[i]);
    for(int j=1;j<=N;j++){
      D[j]-=A[i][j];
    }
  }
  return;
}

int main(){
  scanf("%d %d %d",&N,&M,&X);
  for(int i=1;i<=N;i++){
    scanf("%d",C+i);
    D[i]=0;
    for(int j=1;j<=M;j++){
      scanf("%d",&A[i][j]);
    }
  }
  f(0,0);
  printf("%d\n",min_S);
}
