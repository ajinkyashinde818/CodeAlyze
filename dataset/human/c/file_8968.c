#include <stdio.h>
int test(int x){

  if(x%2 == 0) x /= 2;
  else x=x*3+1;

  return x;

}

int main(){

  int n,result;

  while(1){

    scanf("%d",&n);
    if(n == 0) break;
    result=0;

    while(1){

      if(n == 1) break;

      n=test(n);

      result++;

    }

    printf("%d\n",result);

  }

  return 0;

}
