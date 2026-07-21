#include<stdio.h>
int main(void){
  int x[10000] = {},i = 1,l = 1;;
  while(1){
    scanf("%d",&x[i]);
    if(x[i] == 0) break;
    i++;
  }
  for(;l < i;l++){
    printf("Case %d: %d\n",l,x[l]);
  }
  return 0;
}
