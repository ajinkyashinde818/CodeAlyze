#include <stdio.h>
#include <string.h>

int main (void)
{
    int n,k;
    char s[10];
    scanf("%d",&n);
    scanf("%s",s);
    scanf("%d",&k);
    for(int i=0;i<n;i++)
    {
        if(s[i]!=s[k-1])
        {
            s[i]='*';
        }
    }
    printf(s);
    return 0;
}
