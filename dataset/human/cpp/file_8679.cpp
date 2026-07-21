#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    char a[60][60]={0},b[60][60]={0};
    int n,m,i,j,k,l,flag;
    cin >> n >> m;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin >> a[i][j];
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            cin >> b[i][j];
        }
    }
    for(i=0;i<n-m+1;i++)
    {
        for(j=0;j<n-m+1;j++)
        {
            flag=0;
            for(k=i;k<i+m;k++)
            {
                for(l=j;l<j+m;l++)
                {
                    if(a[k][l]!=b[k-i][l-j])
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==1) break;
            }
            if(flag==0) break;
        }
        if(flag==0) break;
    }
    if(flag==0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
