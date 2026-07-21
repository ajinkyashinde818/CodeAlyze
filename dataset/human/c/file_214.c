#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _min(_x, _y) ((_x)>(_y)?(_y):(_x))
#define _abs(_x) ((_x)>0?(_x):(-(_x)))
int main(void)
{
  long N,A,minA,minuscount,index,answer;
  scanf("%ld", &N);
  minA = 1000000000;
  minuscount = 0;
  answer = 0;
  for (index = 0; index < N; ++index) {
    scanf("%ld", &A);
    if (A < 0) minuscount++;
    A = _abs(A);
    answer += A;
    minA = _min(minA, A);
  }    
  if ((minuscount+2)/2 == (minuscount+1)/2) {
    answer -= (minA*2);
  }
  printf("%ld\n", answer);
  return 0;
}
