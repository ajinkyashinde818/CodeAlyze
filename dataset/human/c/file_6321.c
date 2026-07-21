#include <stdio.h>

#define MAX 200000

int main(){
  int i;
  int maxprf,minprf,gyo,num[MAX];

  scanf("%d",&gyo);
  for(i=0;i<gyo;i++) scanf("%d",&num[i]);

  minprf=num[0];
  maxprf=num[1]-num[0];
  for(i=1;i<gyo;i++){
    if(maxprf<num[i]-minprf) maxprf=num[i]-minprf;
    if(minprf>num[i]) minprf=num[i];
  }

  printf("%d\n",maxprf);
  
  return 0;
}
