#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int main(void)
{
	int a = 0, b = 0, c = 0,ans = 0;
	scanf("%d%d%d", &a, &b, &c);

	if (b < c)
	{
      if(a + b < c)
      {
		ans = b * 2 + a + 1;
      }
      else
      {
        ans = b + c;
      }
	}
	else
	{
		ans = b + c;
	}

	printf("%d", ans);
	return 0;
}
