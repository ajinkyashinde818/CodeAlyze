#include <stdio.h>

int main(void){
  long n,i,x,j;
  long R[200000],max=-1000000000,min;

  scanf("%ld",&n);

  for(i=0;i<n;i++){
    scanf("%ld",&R[i]);
  }

min=R[0];

for(i=1;i<n;i++){
  x=R[i]-min;
  if(max<x)max=x;
  if(min>R[i])min=R[i];
}

  printf("%ld\n",max);

  return 0;
}
