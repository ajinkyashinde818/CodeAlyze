#include <stdio.h>
#include <string.h>

int main()
{
    char s[600000];
    int q;
    int t,f;
    char c;

    scanf("%s %d",s,&q);
    int i,len = strlen(s);
    for (i = 0; i < len; i++)
    {
        s[250000 + i] = s[i];
    }
    
    int left = 250000 - 1,right = 250000 + len;
    int inv = 1;
    for (i = 0; i < q; i++)
    {
        scanf("%d",&t);
        if(t == 1)inv *= -1;
        else
        {
            scanf("%d %c",&f,&c);
            if(inv == 1)
            {
                if(f == 1)
                {
                    s[left] = c;
                    left--;
                }
                else
                {
                    s[right] = c;
                    right++;
                }
            }
            else
            {
                if(f == 2)
                {
                    s[left] = c;
                    left--;
                }
                else
                {
                    s[right] = c;
                    right++;
                }
            }
        }
    }
    
    if(inv == 1){
        for (i = left + 1; i < right; i++)
        {
            printf("%c",s[i]);
        }
    }else
    {
        for (i = right - 1; i > left; i--)
        {
            printf("%c",s[i]);
        }
        
    }
    
    
}
