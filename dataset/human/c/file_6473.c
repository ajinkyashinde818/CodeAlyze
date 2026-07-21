#include<stdio.h>
#define N 20000
int main(){
  int n,Rt[1000000],max,i,min,j;

  scanf("%d",&n);

  for(i =0;i < n;i++){
    scanf("%d",&Rt[i]);
  }

  max = Rt[1] - Rt[0];
  min = Rt[0];

  for(j = 1;j < n;j++){
    if(max < Rt[j] - min){max = Rt[j] - min;}
    if(min > Rt[j]){min = Rt[j];}
  }

  printf("%d\n",max);

  return 0;
}
