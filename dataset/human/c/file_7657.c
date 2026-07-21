#include<stdio.h>
int main(){
  int i;
  int x[100000];
  
  for (i = 0;; i++) {
    scanf ("%d", &x[i]);
    if (x[i] == 0) {
      break;
    }
  }

  for (i = 0; x[i] != 0; i++) {
    printf ("Case %d: %d\n", i + 1, x[i]);
  }
  
  return 0;
}
