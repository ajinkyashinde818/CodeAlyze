#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_char0(const void *a, const void *b) {
  return *(char *)a - *(char *)b;
}
int compare_char1(const void *a, const void *b) {
  return *(char *)b - *(char *)a;
}

int main()
{
    char s[101],t[101],mini = 26,maxi = 0;
    int len[2],i,j;

    scanf("%s %s",s,t);

    len[0] = strlen(s);
    qsort(s,len[0],sizeof(char),compare_char0);
    len[1] = strlen(t);
    qsort(t,len[1],sizeof(char),compare_char1);

    if(strcmp(s,t) < 0)
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }
    printf("\n");
}
