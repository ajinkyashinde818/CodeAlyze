#include <stdio.h>
#include <string.h>

int main(void) {

  char s[1000000+10];
  scanf("%s", s);
  int length = strlen(s);
  int num;
  long bill_a = 0;
  long bill_b = 1;
  long case1,case2,case3,case4;
  for (int i = 0; i < length; i++) {
    num = s[i]-'0';
    case1 = bill_a+num;
    case2 = bill_b+10-num;
    case3 = bill_a+(num+1);
    case4 = bill_b+10-(num+1);
    bill_a = case1;
    if (case2 < bill_a) {
      bill_a = case2;
    }
    bill_b = case3;
    if (case4 < bill_b) {
      bill_b = case4;
    }
  }
  printf("%ld\n", bill_a);

  return 0;
}
