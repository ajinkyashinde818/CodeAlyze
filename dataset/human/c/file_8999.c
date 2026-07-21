#include<stdio.h>
int main(void){
  int n,count=0;
  scanf("%d",&n);

  while(n!=0){
    count = 0;
    while(n!=1){
      if(n%2 == 0) n /= 2;
      else n = n*3 + 1;
      count ++;
    }
    printf("%d\n",count);
    scanf("%d",&n);
  }
  return 0;
}
