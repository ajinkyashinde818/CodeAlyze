#include <stdio.h>
#include <string.h>
#include <stdlib.h>
static int gt(const void* pa, const void* pb)
{
const char* a=pa;
const char* b=pb;
return (int)*b-(int)*a;
}
static int lt(const void* pa, const void* pb)
{
const char* a=pa;
const char* b=pb;
return (int)*a-(int)*b;
}
int main(void)
{
char s[101], t[101];
scanf("%s%s", s,t);
qsort(s, strlen(s), sizeof(*s), lt);
qsort(t, strlen(t), sizeof(*t), gt);
if(strcmp(s,t)<0)
printf("Yes\n");
else
printf("No\n");
return 0;
}
