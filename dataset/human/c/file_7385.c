#include<stdio.h>
int main(){
  int x[10000], t, s = 0;
  while(1){
    scanf("%d\n", &t);
    if(t == 0) break;
    else { x[s]=t; s++;}
  }
  for(t=0;t<s;t++)printf("Case %d: %d\n", t+1, x[t]);
  return 0;
}
