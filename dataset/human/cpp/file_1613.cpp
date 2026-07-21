#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
const int nmax=100005;
vector<int> v[nmax];
int n,i,k,j,nr;
int main()
{
    cin>>n;
    if(n==1)
    {
        k=1;
        cout<<"Yes\n";
        cout<<2<<'\n';
        cout<<k<<' '<<k<<'\n';
        cout<<k<<' '<<k<<'\n';
        return 0;
    }
    for(i=1;i*(i-1)/2<=n;i++)
        if(i*(i-1)/2==n)
          k=i;
    if(!k)
    {
        cout<<"No";
    }
    else
    {
        cout<<"Yes\n";
        cout<<k<<'\n';
        for(i=1;i<=k;i++)
            for(j=i+1;j<=k;j++)
        {
            ++nr;
            v[i].push_back(nr);
            v[j].push_back(nr);
        }
        for(i=1;i<=k;i++)
        {
            cout<<v[i].size()<<' ';
            for(int j=0;j<v[i].size();j++)
                cout<<v[i][j]<<' ';
            cout<<'\n';
        }
    }
    return 0;
}
