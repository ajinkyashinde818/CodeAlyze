#include<stdio.h>

#define MAX 1000000
#define sqrtMAX 1000

int main(void)
{
  int n;
  int b[MAX+1] = {0};
  int i, j;
  int sum;
  int count;

  // ツエツδ可トツスツテツネツスツづ個づ督づゥツつ「
  b[0] = 1;
  b[1] = 1;
  for(i=4; i<=MAX; i+=2)
      b[i] = 1;
  for(i=3; i<=sqrtMAX; i+=2)
      for(j=i+i; j<=MAX; j+=i)
          b[j] = 1;

  while(scanf("%d", &n)!=EOF) {
      if(n == 0)
          break;
      sum = 0;
      count = 0;
      for(i=2; count<n; i++) {
        if(b[i]==0) {
              count++;
              sum+=i;
        }
      }
      printf("%d\n", sum);
    }
  return 0;
}
