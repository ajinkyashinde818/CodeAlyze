#include<stdio.h>
#define max(a,b) ((a>b?a:b))
int main(){
  int K,N,A0,An,An_old;
  int i, max_delA;
  scanf("%d%d",&K,&N);
  max_delA = 0;
  scanf("%d",&An);
  A0 = An;
  An_old = An;
  for(i=1;i<N;i++){
    scanf("%d",&An);
    max_delA = max(max_delA, An - An_old);
    An_old = An;
  }
  max_delA = max(max_delA, K + A0 - An);
  printf("%d",K-max_delA);
}
