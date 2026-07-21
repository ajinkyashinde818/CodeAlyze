#include <stdio.h>
#include <string.h>
int main(void)
{
    int  a,b[200000],i,j,n=0,m,x,y,z=0;
    char c[10100],s[10100];

    scanf("%d%d",&x,&y);
    for (size_t i = 0; i < x; i++)
    {
     scanf("%d",&b[i]);
     if(b[i]>=y) z++;
    }
    
    printf("%d",z);
    printf("\n");
    return 0;
}
