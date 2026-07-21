#include <stdio.h>
int main(){
  int n,i,j;
  int minv=0,maxv=0;
  scanf("%d",&n);
  int R[n];
  for(i=0;i<n;i++){
    scanf("%d",&R[i]);
  }
  minv=R[0];
  maxv=R[1]-R[0];
  for(j=1;j<n;j++){
    if(maxv<R[j]-minv)maxv=R[j]-minv;
    if(minv>R[j])minv=R[j];
  }
  printf("%d\n",maxv);
  return 0;
}
