#include <stdio.h>
int main(){
  int i,j;
  i = 1;
  j = 1;
  int a[1000000];
  while(1){
    scanf("%d",&a[i]);
    if(a[i] ==0)break;
    ++i;
  }
  while(1){
    printf("Case %d: %d\n",j,a[j]);
    ++j;
    if(j >= i)break;
  }return 0;
}
