#include <stdio.h>

int main() {
  int n,k,a;
  int h[100000];
  scanf("%d %d", &n,&k);
  for(int i=0; i<n;i++) {
    scanf("%d", &h[i]);
  }
  for(int i=0; i<n;i++) {
    if(h[i] >= k)a++;
  }
  printf("%d",a);
}
