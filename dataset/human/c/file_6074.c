#include<stdio.h>

#define N 200000

int main()
{
  int R[N],i,j,k,mim,max;

  scanf("%d",&k);
  for(i=0;i<k;i++){
    scanf("%d",&R[i]);
  }

  max=R[1]-R[0];
  mim=R[0];

  for(j=1;j<k;j++){

    max=(max>R[j]-mim)? max :R[j]-mim;
    mim=(mim<R[j])? mim :R[j];
  }

  printf("%d\n",max);
  return 0;
}
