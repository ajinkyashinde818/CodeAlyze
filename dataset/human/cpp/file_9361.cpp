#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    char a[55][55],b[55][55];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)cin>>a[i][j];
    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++)cin>>b[i][j];
    for(int i=0;i<n-m+1;i++)
    {
        for(int j=0;j<n-m+1;j++)
        {
            int flag=1;
            for(int k=0;k<m;k++)
            {
                for(int l=0;l<m;l++)
                {
                    if(a[k+i][l+j]!=b[k][l]){flag=0;break;}
                }
                if(flag==0)break;
            }
            if(flag==1){cout<<"Yes"<<endl;return 0;}
        }
    }
    cout<<"No"<<endl;
}
