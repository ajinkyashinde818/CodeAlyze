#include<stdio.h>

int main(void)
{
    char n[4];
    scanf("%s",n);
    while((10>atoi(n))||(atoi(n)>99))
    {
        scanf("%s",n);
    }
    if((n[0]=='9')||(n[1]=='9'))
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    return 0;
}
