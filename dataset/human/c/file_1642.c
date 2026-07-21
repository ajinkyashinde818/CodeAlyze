#include<stdio.h>

int main() {
     int n, a[21], b[51], c[51], sum=0;
     scanf("%d", &n);
     for (int i = 0; i < n; i++) {
          scanf("%d", &a[i]);
     }
     for (int i = 0; i < n; i++) {
          scanf("%d", &b[i]);
          sum+=b[i];
     }
     for (int i = 0; i < n-1; i++) {
          scanf("%d", &c[i]);
     }
     for (int i = 1; i < n; i++) {

          if (a[i] == a[i-1]+1) {
               sum+=c[a[i-1]-1];
          }
     }
     printf("%d\n", sum);

     return 0;
}
