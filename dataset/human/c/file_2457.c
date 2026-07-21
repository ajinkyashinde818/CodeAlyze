#include<stdio.h>
#include<string.h>

int main()
{
    char a[3];
     int  flag=0;

    scanf("%s",a);
    for(int i=0; i<2; i++)
    {
        if(a[0]!=a[1] && a[1]!=a[2] && a[2]!=a[0])
            flag=1;
    }
    if(flag==1)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    return 0;
}
