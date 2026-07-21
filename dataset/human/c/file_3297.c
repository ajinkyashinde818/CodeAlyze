#include<stdio.h>
int main(void){
  int K,N,i,swap;
  int ans=0;
  int A[200000];
  int Abet[200000];
  scanf("%d",&K);
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);}
  for(i=0;i<N-1;i++){
    Abet[i]=A[i+1]-A[i];}
  Abet[N-1]=K-A[N-1]+A[0];
  for(i=0;i<N-1;i++){
    if(Abet[i]>Abet[i+1]){
      swap=Abet[i];
      Abet[i]=Abet[i+1];
      Abet[i+1]=swap;}}
  for(i=0;i<N-1;i++)
    ans=ans+Abet[i];
  printf("%d",ans);
return 0;
}
