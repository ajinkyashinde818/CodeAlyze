#include <stdio.h>
#include <stdlib.h>

int main()
{
    char x,y;
    int b,c,d,i;
    char a[6]= {'A','B','C','D','E','F'};
    scanf("%c %c",&x,&y);
    for(i=0; i<6; i++)
    {
        if(a[i]==x)
            b=i;
        if(a[i]==y)
            c=i;
    }
    d=b-c;
    if(d>0)
        printf(">\n");
    else if(d==0)
        printf("=\n");
    else
        printf("<\n");
    return 0;
}
