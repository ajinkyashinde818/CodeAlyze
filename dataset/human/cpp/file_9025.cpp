#include <bits/stdc++.h>
using namespace std;


int main()
{
	std::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long test;
    test=1;
    // cin>>test;
    while(test--)
    {
        int n,m,i,j;
        cin>>n>>m;
        char s[n][n],s1[m][m];
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)cin>>s[i][j];
        }
        for(i=0;i<m;i++)
        {
            for(j=0;j<m;j++)cin>>s1[i][j];
        }
        for(i=0;i<=n-m;i++)
        {
            for(j=0;j<=n-m;j++)
            {
                bool match=true;
                for(int a=0;a<m;a++)
                {
                    
                    for(int b=0;b<m;b++)
                    {
                        if(s[i+a][j+b]!=s1[a][b])
                        match=false;
                    }
                }
                if(match)
                {
                    cout<<"Yes";
                    return 0;
                }
            }
        }
        cout<<"No";
    
    }
}
