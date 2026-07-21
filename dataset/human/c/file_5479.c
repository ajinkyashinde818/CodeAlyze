#include<stdio.h>

int main(void){
  int i,j,k;
  int prime[10000],sum[10000];
  int n;

  i = 1;
  k = 3;
  prime[0] = sum[0] = 2;
  while(i<10000){
    n = 1;
    for(j=0;prime[j]*prime[j]<=k;j++){
      if(!(k%prime[j])){
	n = 0;
	break;
      }
    }
    if(n){
      prime[i] = k;
      sum[i] = sum[i-1]+k;
      i++;
    }
    k+=2;
  }

  while(1){
    scanf("%d",&n);
    if(!n)break;
    printf("%d\n",sum[n-1]);
  }

  return 0;
}
