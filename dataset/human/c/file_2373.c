#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char c[5];
    scanf("%s",c);
    if(strcmp("abc",c)==0)
    {
        printf("Yes\n");}
        else if(strcmp("acb",c)==0)
        {
            printf("Yes\n");
        }
        else if(strcmp("bac",c)==0)
        {
            printf("Yes\n");
        }
        else if(strcmp("bca",c)==0)
        {
            printf("Yes\n");
        }
        else if(strcmp("cab",c)==0)
        {
            printf("Yes\n");
        }
        else if(strcmp("cba",c)==0)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }

    return 0;
}
