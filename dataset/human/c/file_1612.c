#include <stdio.h>
#include <string.h>

int main(void) {

  char s[100001];
  scanf("%s", s);
  long length = strlen(s);
  long left = 0;
  long right = length-1;
  long insert = 0;
  while (left < right) {
    if (s[left] == s[right]) {
      left++;
      right--;
    } else if (s[left] == 'x') {
      left++;
      insert++;
    } else if (s[right] == 'x') {
      right--;
      insert++;
    } else {
      printf("-1\n");
      return 0;
    }
  }
  printf("%ld\n", insert);

  return 0;
}
