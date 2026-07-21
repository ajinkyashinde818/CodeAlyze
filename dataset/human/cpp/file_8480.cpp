#include <iostream>
using namespace std;
int main()
{
    int n,m;
    string a[55],b[55];
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<m;i++)
        cin>>b[i];
    for(int i=0;i<=n-m;i++)
    {
        for(int j=0;j<=n-m;j++)
        {
            bool found=true;
            for (int k=0;k<m;k++)
            {
                for(int l=0; l<m; l++)
                {
                    if(a[i+k][j+l]!=b[k][l])
                    {
                        found=false;
                        break;
                    }
                }
                if(!found) break;
            }
            if(found)
            {
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }
    cout<<"No"<<endl;
    return 0;
}
