#include<stdio.h>
#include<ctype.h>

int main(void)
{
    int ans[4]={};
    int coef=0,k=0,c=0,formula=0;
    int i,j;

    scanf("%d%*c",&k);
    for(i=0;i<k;i++)
    {
        coef=1;
        formula=0;
        int scale[2][4]={};
        while(1)
        {
            scanf("%c",&c);
            //printf("%c ",c);
            if(c==10)
            {
                break;
            }
            if(isdigit(c))
            {
                coef=c-'0';
        //        printf("coef=%d,",coef);
            }
            else if(isalpha(c))
            {
                switch(c)
                {
                    case 'm':
                    scale[formula][3]=coef;
                    break;
                    case 'c':
                    scale[formula][2]=coef;
                    break;
                    case 'x':
                    scale[formula][1]=coef;
                    break;
                    case 'i':
                    scale[formula][0]=coef;
                    break;
                    default:
                    break;
                }
                coef=1;
            }
            else
            {
                formula=1;
            }
        }

        for(j=0;j<4;j++)
        {
            int x=scale[0][j]+scale[1][j]+ans[j];
            ans[j]=x%10;
            ans[j+1]+=x/10;
        }

        for(j=3;j>=0;j--)
        {
            if(ans[j]!=0)
            {
                if(ans[j]==1)
                {
                    switch(j)
                    {
                        case 0:
                        printf("i");
                        break;
                        case 1:
                        printf("x");
                        break;
                        case 2:
                        printf("c");
                        break;
                        case 3:
                        printf("m");
                        break;
                        default:
                        break;
                    }
                }
                else
                {
                    switch(j)
                    {
                        case 0:
                        printf("%di",ans[j]);
                        break;
                        case 1:
                        printf("%dx",ans[j]);
                        break;
                        case 2:
                        printf("%dc",ans[j]);
                        break;
                        case 3:
                        printf("%dm",ans[j]);
                        break;
                        default:
                        break;
                    }
                }
            }
        }
        printf("\n");
        for(j=0;j<4;j++)
        {
            ans[j]=0;
        }
    }
    return 0;
}
