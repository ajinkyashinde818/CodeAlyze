#include <stdio.h>

int main(){
  int a,b,k;
  scanf("%d %d %d",&a,&b,&k);
  int d;
  if(a > b){
    d = a - b;
  }else if (a < b){
    d = b - a;
  }else{
    d = a;
  }
  int count = 0;
  for(int i=d;d>0;d--){
    if (a%d==0 && b%d==0){
      count += 1;
      if (count == k){
        printf("%d\n",d);
      }
    }
  }
  return 0;
}
