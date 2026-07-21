#include <stdio.h>

int main(void){

  char s[100000+1];
  int end;
  for (int i = 0; i < 100000+1; i++) {
    scanf("%c", &s[i]);
    if (s[i] == '\n') {
      end = i-1;
      break;
    }
  }
  int q;
  scanf("%d", &q);
  int t[q][2];
  char tc[q];
  for (int i = 0; i < q; i++) {
    scanf("%d", &t[i][0]);
    if (t[i][0] == 2) {
      scanf("%d %c", &t[i][1], &tc[i]);
    } else {
      t[i][1] = 0;
      tc[i] = '0';
    }
  }

  int top = 1;
  char left[200000];
  int left_end = -1;
  char right[200000];
  int right_end = -1;

  for (int i = 0; i < q; i++) {
    if (t[i][0] == 1) {
      top *= -1;
    } else {
      if ((t[i][1] == 1 && top == 1) || (t[i][1] == 2 && top == -1)) {
        left_end++;
        left[left_end] = tc[i];
      } else {
        right_end++;
        right[right_end] = tc[i];
      }
    }
  }

  if (top == 1) {
    for (int i = 0; i <= left_end; i++) {
      printf("%c", left[left_end-i]);
    }
    for (int i = 0; i <= end; i++) {
      printf("%c", s[i]);
    }
    for (int i = 0; i <= right_end; i++) {
      printf("%c", right[i]);
    }
  } else {
    for (int i = 0; i <= right_end; i++) {
      printf("%c", right[right_end-i]);
    }
    for (int i = 0; i <= end; i++) {
      printf("%c", s[end-i]);
    }
    for (int i = 0; i <= left_end; i++) {
      printf("%c", left[i]);
    }
  }
  printf("\n");

  return 0;
}
