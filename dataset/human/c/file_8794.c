#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    getchar();
   char a[n][m];
   int flag=1;
   for(i=0;i<n;i++)
   {
       for(j=0;j<m;j++)
       {
           scanf("%c",&a[i][j]);
       }
       getchar();
   }

    if(a[0][0]=='#'&&!(a[0][1]=='#'||a[1][0]=='#'))
    {
       // printf("1\n");
        flag=0;
    }


      if(a[n-1][0]=='#'&&!(a[n-1][1]=='#'||a[n-2][0]=='#'))
       {
          // printf("2\n");
           flag=0;
       }

      if(a[0][m-1]=='#'&&!(a[0][m-2]=='#'||a[1][m-1]=='#'))
       {
       //printf("3\n");
               flag=0;
       }

      if(a[n-1][m-1]=='#'&&!(a[n-1][m-2]=='#'||a[n-2][m-1]=='#'))
       {
           //printf("4\n");
           flag=0;
       }

        for(j=1;j<m-1;j++)
        {
            if(a[0][j]=='#'&&!(a[0][j-1]=='#'||a[0][j+1]=='#'||a[1][j]=='#'))
            {
               // printf("5\n");
                flag=0;
                break;
            }
            if(a[m-1][j]=='#'&&!(a[m-1][j-1]=='#'||a[m-1][j+1]=='#'||a[m-2][j]=='#'))
                {
                   // printf("6\n");
                    flag=0;
                    break;
                }
        }
       for(i=1;i<n-1;i++)
       {
           if(a[i][0]=='#'&&!(a[i+1][0]=='#'||a[i-1][0]=='#'||a[i][1]=='#'))
           {//printf("7\n");
               flag=0;break;
           }
           if(a[i][m-1]=='#'&&!(a[i+1][m-1]=='#'||a[i-1][m-1]=='#'||a[i][m-2]=='#'))
              {//printf("8\n");
                  flag=0;break;
              }
       }
       for(i=1;i<n-1;i++)
       {
           for(j=1;j<m-1;j++)
           {
               if(a[i][j]=='#'&&!(a[i][j-1]=='#'||a[i][j+1]=='#'||a[i-1][j]=='#'||a[i+1][j]=='#'))
               {//printf("9\n");
                   flag=0;
                   break;
               }
           }
       }
       if(n==1&&m==1)
        flag=0;
       if(flag==0)
       printf("No\n");
       else
        printf("Yes\n");
    return 0;
}
