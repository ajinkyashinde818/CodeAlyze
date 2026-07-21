#include<stdio.h>
#include<string.h>
int cmp(char s[100001],char t[100001],int st,int fin)
{
    if(strlen(t)>(fin-st+1))
    {
        return 0;
    }
    int j=0;
    for(int i=st;i<=fin;i++)
    {
        if(s[i] != t[j])
        {
            break;
        }
        j++;
    }
    if(j==(fin-st+1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}
int main(void)
{
    int point=0,judge=0;
    char s[100001],t[100001];
    fgets(s,sizeof(s),stdin);
    int len = strlen(s) - 1;
    while(point<len-4)
    {
        if(cmp(s,"dream",point,point+4))
        {
            judge = 1;
            point = point + 5;
            if(s[point] == 'e'&&s[point+1] == 'r'&&cmp(s,"erase",point,point+4)==0)
            {
                point = point+2;
            }
        }
        if(cmp(s,"erase",point,point+4))
        {
            judge = 1;
            point = point + 5;
            if(s[point] == 'r')
            {
                point++;
            }
        }
        if(judge==0)
        {
            printf("NO");
            return 0;
        }
        else
        {
            judge = 0;
        }
        
    }
    
    if(point==len)
    printf("YES");
    else
    {   
        printf("NO");
    }
    
    
}
