#include <stdio.h>
#include <stdbool.h>

void doublets_occur(void) {
  bool yes = false;
  int n;
  scanf("%d", &n);
  bool arr[n];
  for (int i = 0; i < n; i++) {
    int d1, d2;
    scanf("%d%d", &d1, &d2);
    if (d1 == d2) {
      arr[i] = true;
    } else {
      arr[i] = false;
    }
  }
  for (int i = 0; i < n - 2; i++) {
    if (arr[i] && arr[i+1] && arr[i+2]) {
      yes = true;
      break;
    }
  }
  if (yes) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
}


int main(void) {
  doublets_occur();
  return 0;
}
