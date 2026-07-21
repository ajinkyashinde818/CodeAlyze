#include<stdio.h>
#define n 200000

int main(){

int R[n],maxv=-1000000000,minv,num,j;
  scanf("%d",&num);
  for(j=0;j<num;j++){
    scanf("%d",&R[j]);
}
  minv = R[0];
  for(j=1;j<num;j++){
    if(maxv<R[j]-minv)maxv=R[j]-minv;
    if(minv>R[j])minv=R[j];
}
printf("%d\n",maxv);

  return 0;
}
