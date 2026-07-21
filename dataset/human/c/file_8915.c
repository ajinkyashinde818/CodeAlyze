#include <stdio.h>
int main(void)
{
    int h,w;
    scanf("%d %d\n",&h,&w);
    char str[53][53]={"$"};
    for(int p=1;p<h+1;p++)
    {
        for(int q=1;q<w+1;q++)
        {
            scanf("%c",&str[p][q]);
        }
        scanf("\n");
    }
    int up[5]={1,0,-1,0};
    int side[5]={0,1,0,-1};
    int ans=1;
    int check=0;
    for(int r=1;r<h+1;r++)
    {
        for(int s=1;s<w+1;s++)
        {
            if(str[r][s]=='#')
            {
                check=0;
                for(int t=0;t<4;t++)
                {
                    if(str[r+up[t]][s+side[t]]=='#')check=1;
                }
                if(check==0)
                {
                    printf("No");
                    return 0;
                }
            }
        }
    }
    printf("Yes");
    return 0;
}
