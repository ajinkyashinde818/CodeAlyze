#include <stdio.h>
#include <sysexits.h>
#include <math.h>

int main(void){
  int b,i,j,num,N,M;
  char S[1],c;
  int a[4];
  if(scanf("%d %d",&N,&M)>2){
    printf("error");
   exit(0);
  }
  if(M+1>N){
    printf("Yes");
  }
  else{
    printf("No");
  }
  return 0;
}
