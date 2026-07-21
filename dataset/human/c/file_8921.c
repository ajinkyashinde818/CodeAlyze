#include<stdio.h>
int main()
{
    int h,w,i,j,fh=0;
    char s[60][60];
    scanf("%d %d",&h,&w);
    getchar();
    for(i=0;i<h;i++)
    {
        for(j=0;j<w;j++)
        {
            scanf("%c",&s[i][j]);
        }
        if(j==w)
            getchar();
    }
    for(i=0;i<h;i++)
        for(j=0;j<w;j++)
    {
        if(s[i][j]=='#')
        {
            if(s[i-1][j]!='#'&&s[i+1][j]!='#'&&s[i][j-1]!='#'&&s[i][j+1]!='#')
            {
                fh=1;break;
            }
        }
    }
    if(fh==1)
        printf("No\n");
    else
        printf("Yes\n");
    return 0;
}
