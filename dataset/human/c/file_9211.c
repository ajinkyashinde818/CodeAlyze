#include<stdio.h>
#include<stdlib.h>

int main(){
  int N,K,sum=0;
  scanf("%d %d",&N,&K);
  int *a=(int*)malloc(sizeof(int)*N);
  for(int i=0;i<N;i++){
  	scanf("%d",&a[i]);
    if(a[i]>=K)sum++;
  }
  printf("%d\n",sum);
  return 0;
}
