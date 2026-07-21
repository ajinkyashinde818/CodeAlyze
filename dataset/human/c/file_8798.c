#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int mr[4]={-1,0,0,1};
int mc[4]={0,-1,1,0};
char z[100][100];
int main()
{
    int H,W;
    scanf("%d %d",&H,&W);
    int flag=0;
    for(int i=0;i<H;i++)
    {
        getchar();
        scanf("%s",z[i]);
    }
    for(int i=0;i<H;i++)
    {
        for(int k=0;k<W;k++)
        {
            if(z[i][k]=='#')
            {
                int pp=0;
                for(int p=0;p<4;p++)
                {
                    int nr,nc;
                    nr=i+mr[p];
                    nc=k+mc[p];
                    if(nr>=0 && nc>=0 && nr<H && nc<W)
                    {
                        if(z[nr][nc]=='#')
                            pp=1;
                    }
                }
                if(pp==0)
                    flag=1;
            }
          //  if(flag==1)
          //      printf("%d-%d\n",i,k);
            
        }
        
    }
    if(H==W && H==1 && z[0][0]=='#')
        printf("Yes\n");
    else
    if(!flag)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
