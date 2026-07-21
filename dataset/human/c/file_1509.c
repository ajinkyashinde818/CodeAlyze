#include <stdio.h>
#include <string.h>

int main(void)
{
        int n;
        char a[2],b[2];
        scanf("%s%s",a,b);
        n=strcmp(a,b);
        if(n>0)printf(">\n");
        else if(n==0)printf("=\n");
        else printf("<\n");
        return 0;
}
