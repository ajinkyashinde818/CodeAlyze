#include <stdio.h>
int main(void)
{
  int n;

  while(1){
    scanf("%d",&n);
    if(n){
      int cnt=0;
      while(n!=1){
        if(n%2==0)
	  n/=2;
        else
	  n=3*n+1;
        cnt++;
      }
      printf("%d\n",cnt);
    }
    else
      break;
  }
  return 0;
}
