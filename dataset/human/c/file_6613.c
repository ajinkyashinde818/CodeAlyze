#include<stdio.h>

#define N 200000

int main(){
  int i,j,n,minv,maxv;
  int R[N];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&R[i]);
  }

  maxv = R[1] - R[0];
  minv = R[0];
  for(j=1;j<n;j++){
    maxv = (maxv > R[j] - minv)? maxv :R[j] - minv;
    minv = (minv < R[j])? minv :R[j];
  }

  printf("%d\n",maxv);
  return 0;
}
