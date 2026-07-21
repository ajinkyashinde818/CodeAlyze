#include<iostream>
using namespace std;
int n,m;
char c[50][50],s[50][50];
int main()
{
    cin>>n>>m;
    bool ok=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)cin>>c[i][j];
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++)cin>>s[i][j];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i+m-1>=n or j+-1>=n)continue;
            bool can=1;
            for(int k=0;k<m;k++)
            {
                for(int l=0;l<m;l++)
                {
                    if(c[i+k][j+l]!=s[k][l])can=0;
                }
            }
            if(can){
              ok=1; break;
            }
        }
    }
    cout<<(ok?"Yes":"No")<<endl;
}
