#include<stdio.h>
int main(void)
{
  int flag=0,i,N,S,a[100000];


  scanf("%d",&N);

  if(N-90 > 0){
    flag=1;
  }

  while(N-10 > 0){
    N=N-10;
  }

  if(N==9){
    flag=1;
  }

  
  if(flag == 1){
    printf("Yes\n");
  } else {
    printf("No\n");
  }
  
  return 0;
}
