#include <stdio.h>
#define MAX(a,b) ((a > b) ? a : b)

int main ()
{
  int A,B,K,i,j,l;
  
  scanf("%d%d%d", &A,&B,&K);

  for(i = MAX(A,B) ; i >= 1 ; i-- ){

    if(A % i == 0 && B % i == 0){
      j++;
      if(j == K){
	l = i;
      }
    }
  }
  
  printf("%d\n", l);

  return 0;
}
