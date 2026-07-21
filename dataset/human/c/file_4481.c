#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef long long ll;


int main()
{
    int n;
    scanf("%d",&n);
    int d[n][2];
    int h[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&d[i][0],&d[i][1]);
        if(d[i][0]==d[i][1])
        {
            h[i]=1;
        }
        else
        {
            h[i]=0;
        }
    }
    
    int maxs=0;
    int str=0;

    for(int i=0;i<n;i++)
    {
        if(h[i]==1)
        {
            str=str+1;
            maxs=fmax(maxs,str);
        }
        else
        {
            str=0;
        }
        
    }

    
    if(maxs>2)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    

    return 0;
}
