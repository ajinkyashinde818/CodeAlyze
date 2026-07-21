#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=2e5+10;
int a[maxn],b[maxn];//,c[maxn];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    for(int i=1; i<=n; i++)cin>>a[i];
    for(int i=1; i<=n; i++)cin>>b[i];
    int r=n,l;
    reverse(b+1,b+1+n);//for(int i=1; i<=n; i++)c[i]=b[r--];
    l=1;r=n;
    for(int i=1; i<=n; i++){
        if(a[i]!=b[i])continue;
        if(l<i&&b[l]!=a[i]&&a[l]!=b[i]){
            swap(b[l],b[i]);
            l++;
        }else if(i<r&&b[r]!=a[i]&&a[r]!=b[i]){
            swap(b[r],b[i]);
            r--;
        }else return cout<<"No"<<endl,0;
    }
    cout<<"Yes"<<endl;
    for(int i=1; i<=n; i++)cout<<b[i]<<' ';
    return 0;
}
