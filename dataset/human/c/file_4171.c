#include <stdio.h>

#define MIN(a,b) ((a)<(b)?(a):(b))


int main()
{
  int cnt;
  int A,B,K;
  int result;
  int min;
  int k;
  int i;

  cnt = scanf("%d %d %d", &A,&B,&K);

  min = MIN(A,B);

  k=0;
  for(i=min; i>0; i--) {
    if(((A%i) == 0) && ((B%i) == 0)) k++;
    if (k==K) break;
  }

  printf("%d", i);
  
  return 0;
}
