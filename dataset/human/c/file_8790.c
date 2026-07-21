#include<stdio.h>
char s[55][55];
int main()
{
    int h,w,i,j,flag=1;
    scanf("%d%d",&h,&w);
    for(i=0;i<h;i++)
    {
          scanf("%s",&s[i]);
    }
    for(i=0;i<=h;i++)
    {
        for(j=0;j<h;j++)
        {
           if(s[i][j]=='#')
           {
               if(s[i-1][j]=='.'&&s[i][j-1]=='.'&&s[i+1][j]=='.'&&s[i][j+1]=='.')
                flag=0;
           }
        }
    }
    if(flag==0)
        printf("No");
    else
        printf("Yes");
    return 0;
}
