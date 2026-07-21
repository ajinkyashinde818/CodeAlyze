#include<stdio.h>

int main(){


  int num,i,j,R[200000],minv=0,maxv;

  scanf("%d",&num);
  for(i=0;i<num;i++){
    scanf("%d",&R[i]);
  }

  maxv =R[1]-R[0];
  minv = R[0];

  for(j=1;j<=num-1;j++){

    if(maxv > R[j]-minv)maxv = maxv;
    else maxv = R[j]- minv;

    if(minv < R[j])minv=minv;
    else minv = R[j];

  }

  printf("%d\n",maxv);
  return 0;
}
