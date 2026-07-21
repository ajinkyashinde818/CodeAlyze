#include <stdio.h>
int main(){
  int a,b,k,div;
  scanf("%d%d%d",&a,&b,&k);
  if (a>b){
    div=b+1;
  }
  else {
    div=a+1;
  }
  while (k>0){
    div--;
    if (a/div*div==a && b/div*div==b){
      k--;
    }
  }
  printf("%d\n",div);
  return 0;
}
