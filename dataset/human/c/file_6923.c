#include <stdio.h>
#include <stdlib.h>
int asc(const void *a, const void *b)
{
    return *(long int *)a - *(long int *)b;
}
int dis(const void *a, const void *b)
{
    return *(long int *)b - *(long int *)a;
}
int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
  printf((a==b)?"Yes":"No");
    return 0;
}
