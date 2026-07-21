#include <stdio.h>
int main(void){
  int n,k;
  scanf("%d%d",&n,&k);
  int count=0,tmp;
  for(int i=0;i<n;i++){
    scanf("%d",&tmp);
    if(tmp>=k)count++;
  }
  printf("%d\n",count);
  return 0;
}
