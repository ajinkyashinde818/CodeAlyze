#include<stdio.h>

int main(){

  int i,n,m,M,Max;

  scanf("%d%d%d",&n,&m,&M);
  Max = M-m;
  if(M<m) m=M;
  for(i=2;i<n;i++){
    scanf("%d",&M);
    if(M-m>Max) Max = M-m;
    if(M<m) m=M;
  }

  printf("%d\n",Max);

  return 0;
}
