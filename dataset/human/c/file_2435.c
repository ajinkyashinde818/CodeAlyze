#include<stdio.h>

int main()
{
    int i,j,len,check[3]={0,0,0};
    char s[4];
    
    len=scanf("%s",s);
    
    for(i=0;i<3;i++)
    {
        switch(s[i])
        {
        case 'a':
            j=0;
            break;
        case 'b':
            j=1;
            break;
        default:
            j=2;
            break;
        }
        if(check[j] == 0)
        {
            check[j] = 1;
        }
        else
        {
            break;
        }
    }
    if(i == 3)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    
    return 0;
}
