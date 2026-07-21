#include <stdio.h>

int main()
{
  int i;
  int data_set;
  int number[10000];
  
  for (i = 0;;i++) {
    scanf("%d", &number[i]);
    if (!number[i]) break;
    data_set = i;
  }

  for (i = 0; i <= data_set; i++) {
    printf("Case %d: %d\n", i + 1, number[i]);
  }
  
  return 0;
}
