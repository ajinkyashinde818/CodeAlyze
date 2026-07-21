#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int scmp(const void *a, const void *b){
    return *(char *)a - *(char *)b;
}
int tcmp(const void *a, const void *b){
    return *(char *)b - *(char *)a;
}
int main(void)
{
    char s[110], t[110];
    scanf("%s%s",s,t);
    qsort(s, strlen(s), sizeof(char), scmp);
    qsort(t, strlen(t), sizeof(char), tcmp);
    puts(strcmp(s,t)<0?"Yes":"No");
    return 0;
}
