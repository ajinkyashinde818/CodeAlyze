#include <stdio.h>

int main(){
  int n,k;
  if(scanf("%d%d",&n,&k)==1){}
  int i,tmp;
  int count=0;
  for(i=0;i<n;i++){
    if(scanf("%d",&tmp)==1){}
    if(tmp>=k){count++;}
  }
  printf("%d",count);
  return 0;
}
