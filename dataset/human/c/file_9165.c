#include <stdio.h>

void init(int h[],int N);
int comp(int h[],int N,int K);
int main(){
  int N,K,ct;
  int h[100000];

  scanf("%d %d",&N,&K);
  init(h,N);
  printf("%d\n",comp(h,N,K));

  return 0;
}
void init(int h[],int N){
  for(int i=0;i<N;i++)scanf("%d",&h[i]);
}
int comp(int h[],int N,int K){
  int ct=0;
  for(int i=0;i<N;i++)if(h[i]>=K)ct++;
  return ct;
}
