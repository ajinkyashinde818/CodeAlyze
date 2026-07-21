#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int main()
{
    int t;
    
    // scanf("%d",&t);
    
    t=1;
    
    while(t--)
    {
        int n,m;
        
        scanf("%d%d",&n,&m);
        
        char A[n][n],B[m][m];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                scanf(" %c",&A[i][j]);
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<m;j++)
                scanf(" %c",&B[i][j]);
        }
        
        bool poss=false;
        
        for(int i=0;i<=n-m;i++)
        {
            for(int j=0;j<=n-m;j++)
            {
                bool match=true;
                
                for(int k=0;k<m;k++)
                {
                    for(int l=0;l<m;l++)
                    {
                        if(A[i+k][j+l]!=B[k][l])
                            match=false;
                    }
                }
                
                if(match)
                    poss=true;
            }
        }
        
        poss?printf("Yes"):printf("No");
    }

    return 0;
}
