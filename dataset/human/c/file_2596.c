#include <stdio.h>

int main(void) {
  int cnt[3] = {};
  char S[4];
  scanf("%s", S);
  for (int i = 0; i < 3; i++) {
    cnt[S[i] - 'a']++;
  }

  if (cnt[0] == 1 && cnt[1] == 1 && cnt[2] == 1) {
    puts("Yes");
  } else {
    puts("No");
  }

  return 0;
}
