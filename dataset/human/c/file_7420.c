#include<stdio.h>

int main(void)
{
  int i = 0, cnt = 0, num[10000];

  do {
    scanf("%d", &num[i]);
    i++;
    cnt++;
  }while(num[i-1] != 0);

  for(i = 0; i < cnt - 1; i++) {
    printf("Case %d: %d\n", i + 1, num[i]);
  }

  return 0;
}
