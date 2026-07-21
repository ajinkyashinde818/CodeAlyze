#include<stdio.h>
#include<string.h>
int main()
{
    char s[100000];
    scanf("%s",s);
    long int len=strlen(s);
    long int i=len-1;
    int flag=0;
    while(flag==0 && i>=0)
    {
        if(s[i]=='m')
        {
            if(s[i-1]!='a' || s[i-2]!='e' || s[i-3]!='r' || s[i-4]!='d')
            {
                flag=1;
            }
            else
            {
                i=i-5;
            }
        }
        else if(s[i]=='r' && s[i-1]=='e')
        {
            if(s[i-2]=='m')
            {
                if(s[i-3]!='a' || s[i-4]!='e' || s[i-5]!='r' || s[i-6]!='d')
                {
                    flag=1;
                }
                else
                {
                    i=i-7;
                }
            }
            else if(s[i-2]=='s')
            {
                if(s[i-3]!='a' || s[i-4]!='r' || s[i-5]!='e')
                {
                    flag=1;
                }
                else
                {
                    i=i-6;
                }
            }
            else
            {
                flag=1;
            }
        }
        else if(s[i]=='e')
        {
            if(s[i-1]!='s' || s[i-2]!='a' || s[i-3]!='r' || s[i-4]!='e')
            {
                flag=1;
            }
            else
            {
                i=i-5;
            }
        }
        else
        {
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}
