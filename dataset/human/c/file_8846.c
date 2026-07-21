#include<stdio.h>
int main()
{
    int h,w,i,j,flag=1;
    char a[55][55];
    scanf("%d %d",&h,&w);
    getchar();
    for(i=0; i<h; i++)
    {
        for(j=0; j<w; j++)
            scanf("%c",&a[i][j]);
        getchar();
    }
    for(i=0; i<h; i++)
    {
        for(j=0; j<w; j++)
        {
            if(a[i][j]=='#')
            {
                if(i==0)
                {
                    if(j==0)
                    {
                        if(a[i+1][j]!=a[i][j]&&a[i][j+1]!=a[i][j])
                        {
                            flag=0;
                            break;
                        }
                    }
                    else if(j==w-1)
                    {
                        if(a[i+1][j]!=a[i][j]&&a[i][j-1]!=a[i][j])
                        {
                            flag=0;
                            break;
                        }
                    }
                    else
                    {
                        if(a[i+1][j]!=a[i][j]&&a[i][j-1]!=a[i][j]&&a[i][j+1]!='#')
                        {
                            flag=0;
                            break;
                        }
                    }
                }
                else if(i==h-1)
                {
                    if(j==0)
                    {
                        if(a[i-1][j]!=a[i][j]&&a[i][j+1]!=a[i][j])
                        {
                            flag=0;
                            break;
                        }
                    }
                    else if(j==w-1)
                    {
                        if(a[i-1][j]!=a[i][j]&&a[i][j-1]!=a[i][j])
                        {
                            flag=0;
                            break;
                        }
                    }
                    else
                    {
                        if(a[i-1][j]!=a[i][j]&&a[i][j-1]!=a[i][j]&&a[i][j+1]!='#')
                        {
                            flag=0;
                            break;
                        }
                    }
                }
                else
                {
                    if(j==0)
                    {
                        if(a[i-1][j]!=a[i][j]&&a[i][j+1]!='#'&&a[i+1][j]!='#')
                        {
                            flag=0;
                            break;
                        }
                    }
                    else if(j==w-1)
                    {
                        if(a[i-1][j]!=a[i][j]&&a[i+1][j]!=a[i][j]&&a[i][j-1]!='#')
                        {
                            flag=0;
                            break;
                        }
                    }
                    else
                    {
                        if(a[i-1][j]!=a[i][j]&&a[i+1][j]!='#'&&a[i][j-1]!=a[i][j]&&a[i][j+1]!='#')
                        {
                            flag=0;
                            break;
                        }
                    }
                }
            }

        }
        if(flag==0)
            break;
    }
    if(flag==0)
        printf("No\n");
    else
        printf("Yes\n");
    return 0;
}
