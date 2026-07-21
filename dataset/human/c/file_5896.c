#include <stdio.h>

int main(){
  int min,now,value,n,i;

  scanf("%d",&n);

  scanf("%d%d",&min,&now);
  value=now-min;
  if(now<min)min=now;
  
  
  for(i=2;i<n;i++){
    scanf("%d",&now);

    if(value<now-min) value=now-min;
    if(now<min) min=now;
  }

  printf("%d\n",value);

  return 0;
}
