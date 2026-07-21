#include<stdio.h>

int main(void){
  int i,j,k;
  int prime[10000],sum[10000];
  int n;
  int ans;

  i = 1;
  k = 3;
  prime[0] = sum[0] = 2;
  while(i<10000){
    for(j=0;j<i;j++){
      if( !(k%prime[j]) )break;
    }
    if(j==i){
      prime[i] = k;
      sum[i] = sum[i-1]+k;
      i++;
    }
    k++;
  }

  while(1){
    scanf("%d",&n);
    if(!n)break;
    printf("%d\n",sum[n-1]);
  }

  return 0;
}
