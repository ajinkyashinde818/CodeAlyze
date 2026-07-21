#include<iostream>
using namespace std;
int main()
{
    int m,n;
    cin>>n>>m;
    char A[55][55],B[55][55];
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            cin>>A[i][j]; 
    }
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= m; j++)
            cin>>B[i][j];
    }
    for(int i = 1; i <= n - m + 1; i++)
    {
        for(int j= 1; j <= n - m + 1; j++)
        {
            bool flag = true;
            for(int a = 1; a <= m; a++)
            {
                for(int b = 1; b <= m; b++)
                {
                    if(A[i+a-1][j+b-1]!=B[a][b])
                    {
                        flag = false;
                        break;
                    }
                    
                }
                if(!flag)
                    break;
                
            }
            if(flag)
            {
                cout<<"Yes";
                return 0;
            }
        }
    }
    cout<<"No";
    return 0;
}
