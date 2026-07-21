#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main()
{
    int c=0,a=0,b=0,i;
    char s[3]= {'\0'};
    scanf("%c%c%c",&s[0],&s[1],&s[2]);
    for(i=0; i<3; i++)
    {
        if(s[i]=='a')
            a++;
        if(s[i]=='b')
            b++;
        if(s[i]=='c')
            c++;
    }
    if(a==1&&b==1&&c==1)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
