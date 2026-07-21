#include<stdio.h>
int main() {
  int n = 0,kazu[10000],a,i;
  for(n = 0;n < 10000;n++){
    scanf("%d",&a);
    if(a == 0) break;
    kazu[n] = a;
  }
  for(i = 1;i <= n;i++){
    printf("Case %d: %d\n",i,kazu[i-1]);
}
return 0;
}
