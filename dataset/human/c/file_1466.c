#include<stdio.h>

int main(void)
{
  int N;
  int a, b;
  scanf("%d", &N);
  
  a = N / 10;
  b = N % 10;
  
  if(a == 9){
    printf("Yes\n");
  }else{
    if(b == 9){
      printf("Yes\n");
    }else{
      printf("No\n");
    }
  }
  
  return 0;
}
