#include<stdio.h>

int main(void) {
  int n, d1, d2, count=0;
  scanf("%d", &n);
  int i;
  for(i=0; i<n; i++) {
    scanf("%d %d", &d1, &d2);
    if(d1 == d2) count++;
    else count = 0;
    if(count==3) {
      printf("Yes\n");
      return 0;
    }
  }
  printf("No\n");
  return 0;
}
