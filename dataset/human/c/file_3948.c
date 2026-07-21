#include<stdio.h>
int main(void){
  int a, b, c, min;
  scanf("%d %d %d", &a, &b, &c);
  if(a < b){
    min = a;
  }
  else{
    min = b;
  }
  
  int i;
  int cnt = 0;
  for(i = min; i > 0; i--){
    if((a % i == 0) && (b % i == 0)){
      cnt++;
      if(cnt == c){
        printf("%d\n", i);
        break;
      }
    }
  }
  return 0;
}
