#include <stdio.h>

int main(){
  
  int i,j,n,R[2000000],minv,maxv;
    
  scanf("%d",&n);
  for(i = 0;i< n;i++) scanf("%d",&R[i]);
  
  minv = R[0];
  maxv = (-1)*1000000000;
  for(j = 1;j < n;j++){
    if(maxv < R[j] - minv) maxv = R[j] - minv;
    if(minv > R[j]) minv = R[j];
  }
  
  printf("%d\n",maxv);
  
  return 0;
}
