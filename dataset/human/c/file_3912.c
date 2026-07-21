#include <stdio.h>
#include <stdlib.h>
#include <float.h>

#define _max(_x, _y) ((_x)>(_y)?(_x):(_y))
#define _min(_x, _y) ((_x)>(_y)?(_y):(_x))

int main(void)
{
  int A,B,K, i, start;
  int count=0;

  scanf("%d %d %d", &A,&B,&K);
  start = _max(A,B);
  for (i=start; i>0; --i) {
    if ((A%i==0) && (B%i==0)) {
      ++count;
      if (count == K) {
        printf("%d\n", i);
        break;
      }
    }
  }  
  return 0;
}
