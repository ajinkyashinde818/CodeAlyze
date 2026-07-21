#include <bits/stdc++.h>

using namespace std;
string s[55],t[55],q[2505];
int main()
{
    int i,j,m,n,k,cnt=0,flag;
    cin >> m >> n;
    for(i=0;i<m;i++)
    {
        cin >> s[i];
    }
    for(i=0;i<n;i++)
    {
        cin >> t[i];
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<=m-n;j++)
        {
            for(k=0;k<n;k++)
            {
                q[cnt]+=s[i][j+k];
            }
            cnt++;
        }
    }
    for(i=0;i<(m-n+1)*(m-n+1);i++)
    {
        flag=1;
        for(j=0;j<n;j++)
        {
            if(q[i+j*(m-n+1)]!=t[j])
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
        {
            cout << "Yes" << endl;
            break;
        }
    }
    if(flag==0)
    {
        cout << "No" << endl;
    }
    return 0;
}
