#include <stdio.h>
#include <string.h>
int main(void)
{
    int n,k,i;
    char s[11];
    scanf("%d%s%d", &n,s,&k);
    for(i=0; i<n; i++)
    {
        if(strncmp(&s[k-1], &s[i], 1)==0) printf("%c", s[i]);
        else printf("*");
    }
    return 0;
}
