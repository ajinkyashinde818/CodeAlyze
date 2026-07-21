#include <stdio.h>
#include <stdlib.h>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

#define MAX 200000

int main(int argc, char *argv[])
{
    int n, a[MAX];
    int i;
    int minv = 0, maxv = -2000000000;
  
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

      minv = a[0];
      for (i = 1; i < n; i++) {
          maxv = max(a[i] - minv, maxv);
          minv = min(a[i], minv);
      }
      
      printf("%d\n", maxv);
      
      return 0;
}
