#include <stdio.h>

int main(void)
{
 int a[10000];
 int b = 0;
 int c = 0;

 while(b != 1)
{
 scanf("%d", &a[c]);

 if (a[c] != 0)
 printf("Case %d: %d\n", c + 1, a[c]);

 if (a[c] == 0)
 b = 1;

 
 c = c + 1;

}

 return 0;

}
