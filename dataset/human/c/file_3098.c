#include <stdio.h>

int main(){
  int k,n;
  int i,j,max=0;
  scanf("%d",&k);
  scanf("%d",&n);
  int d[n];
  int tr_d=0,y,start;
  
  for(i=0;i<n;i++){
    scanf("%d",&d[i]);
  }
 
  for(i=0;i<n;i++){
    j = i-1;
    if(j<0) j+=n;
    y = d[i]-d[j];
    if(y<0) y*=-1;
    if(y>(k/2)) y = k-y;
    
    if(max<y)
      max = y;
  }
  tr_d = k-max;
  printf("%d",tr_d);
  return 0;
}
