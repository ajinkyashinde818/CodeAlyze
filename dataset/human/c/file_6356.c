#include<stdio.h>

int main(){
  int R[200000];
  int j,n;
  int maxv;
  int minv;
  scanf("%d",&n);
  for(j=0 ; j<n ; j++) scanf("%d",&R[j]);

  maxv = R[1] - R[0];
  minv = R[0];
  
  for(j=1 ; j<n ; j++){
    if(maxv < R[j]-minv) maxv = R[j] - minv;
    if(minv > R[j]) minv = R[j];
  }

  printf("%d\n",maxv);
  return 0;
}
