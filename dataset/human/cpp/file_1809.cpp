#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;\
    int mark[n+1],check[n+1];
    memset(mark,0,sizeof(mark));
    memset(check,0,sizeof(check));
    vector<int>v;
    while(m--)
    {
        int p;
        cin>>p;
        v.push_back(p);
    }
    for(int i=v.size()-1;i>=0;i--)
    {
        if(check[v[i]]==0)
        {
            check[v[i]]=1;
            cout<<v[i]<<endl;
        }
        mark[v[i]]=1;
    }
    for(int i=1;i<=n;i++)
    {
        if(mark[i]==0)
            cout<<i<<endl;
    }
}
