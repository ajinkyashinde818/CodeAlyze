#include <stdio.h>
char s[200];
int i,a[200];
int main()
{
    scanf("%s",s);
    a['a']=0;
    a['b']=0;
    a['c']=0;
    for (i=0;i<=2;i++)
        a[s[i]]+=1;
    if (a['a']==1&&a['b']==1&&a['c']==1) printf("Yes"); else printf("No");
    return(0);
}
