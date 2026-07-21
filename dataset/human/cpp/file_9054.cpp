#include <bits/stdc++.h>

using namespace std;
char a[55][55],b[55][55];
int main(){
   int found = 0;
    int n,m;
    scanf("%d%d",&n,&m);
      int x,y,i,j;
    for(i=0;i<n;i++)
        scanf("%s",&a[i]);
    for(i=0;i<m;i++)
        scanf("%s",&b[i]);

    
        for(x=0;x<n;x++)
            {
            if(x+m>n)break;
            for(y=0;y<n;y++)
                {
                if(y+m>n)break;
                    int valid = 1;
               // printf("point %d %d\n",x,y);
                for(i=0;i<m;i++)
                    {
                    for(j=0;j<m;j++)
                        {
                        if(a[x+i][y+j]!=b[i][j])
                            {
                            valid = 0; break;
                        }
                    }
                    if(valid==0)break;
                }
              //  printf("%d \n",valid);
                if(valid)
                    {
                    found =1 ;
                    break;
                }
            }
            if(found==1)break;
        }
    
    if(found==0)printf("No\n");
    else printf("Yes\n");
    return 0;
}
