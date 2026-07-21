#include <stdio.h>

int main() {
  int n;
  int a[50], b[50], c[50];
  int temp = 0;
  int k, l, m;
  scanf("%d", &n);
  for(int i=0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for(int i=0; i < n; i++) {
    scanf("%d", &b[i]);
  }
  for(int i=0; i < n -1; i++) {
    scanf("%d", &c[i]);
  }
  for(int i=0; i < n; i++) {
    k = a[i] - 1;
    if(temp == a[i]) {
      l = a[i] - 2;
      m += c[l];
    }
    m += b[k];
    temp = a[i] + 1;
  }
  printf("%d", m);
}
