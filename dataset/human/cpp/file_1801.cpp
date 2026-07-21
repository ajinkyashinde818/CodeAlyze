#include<bits/stdc++.h>
using namespace std;
map<int,int>mp;
int arr[2000000];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>arr[i];
    }
    for(int i=m;i>=1;i--)
    {
        if(mp[arr[i]]==0)cout<<arr[i]<<endl;
        mp[arr[i]]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(mp[i]==0)cout<<i<<endl;
        mp[i]++;
    }
    return 0;
}
