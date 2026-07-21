#include <stdio.h>

int main(void)

{

 int n, i, j, l;
 int a[200000];

 scanf("%d", &n);

 for(i = 0;i < n; i++)
{

 scanf("%d", &a[i]);

 }

int max = a[1] - a[0];
int min  = a[0];

 for(i = 0;i < n-1; i++)
{
 if(a[i + 1] - min > max)
 max = a[i + 1] - min;

 if(a[i + 1] < min)
 min = a[i + 1];
 
}
 printf("%d\n", max);

 return 0;
}
