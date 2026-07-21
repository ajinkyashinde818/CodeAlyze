#include <stdio.h>

int main(){
  int n,i,max_diff=-1000000000,min;
  scanf("%d",&n);
  scanf("%d",&min);
  for(i=1;i<n;i++){
    int diff,R;  
    scanf("%d",&R);
    diff = R - min;
    if(max_diff < diff)max_diff=diff;
    if(R < min)min=R;
  }
  
  printf("%d\n",max_diff);
  return 0;
}
