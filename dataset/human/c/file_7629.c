#include<stdio.h>

int main(){
  int x;
  int i = 1;
  while(1){
    scanf("%d",&x);
    if(i <= 10000){
      if(1 <= x&&10000 >= x){
        printf("Case %d: %d\n",i,x);
        i++;
    }else if(x == 0){
      break;
    }
  }else break;
}
  return 0;
}
