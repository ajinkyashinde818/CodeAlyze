#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    char arr[n][n],ar[m][m];
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
            cin>>arr[i][j];
    }
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<m;j++)
            cin>>ar[i][j];
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if(arr[i][j]==ar[0][0]&&i+m<=n&&j+m<=n)
            {
                int q=0;
                for (int k=i;k<i+m;k++)
                {
                    for (int h=j;h<j+m;h++)
                    {
                        if(ar[k-i][h-j]!=arr[k][h])
                        {
                            q=1;
                            break;
                        }
                    }
                }
                if(!q)
                {
                    cout<<"Yes"<<endl;
                    return 0;
                }
            }

        }
    }
    cout<<"No"<<endl;
    return 0;
}
