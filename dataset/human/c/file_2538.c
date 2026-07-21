#include<stdio.h>
int main()
{
    char a[4];
    int i,flag=0;
    gets(a);
    for(i=0;i<3;i++)
    {
       if(a[i]=='a'||a[i]=='b'||a[i]=='c')
        flag=1;
    }

    if(flag==1&&a[0]!=a[1]&&a[0]!=a[2]&&a[1]!=a[2])
        printf("Yes\n");
    else
         printf("No\n");
    return 0;
}
