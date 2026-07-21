#include<stdio.h>

int main(){

  int i,n,kari,count;

  while(1){
    count = 0;
    scanf("%d",&n);
    if(n == 0) break;

    while(n != 1){
      if(n%2 == 0)
	n /= 2;
      else
	n = 3 * n +1;
      count++;
    }

    printf("%d\n",count);
  }

  return 0;
}
