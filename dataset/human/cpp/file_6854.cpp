#include<bits/stdc++.h>
using namespace std;
const int MX=2e5+5;
int n,x,l,r,p,q,a[MX],b[MX];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];
    reverse(b,b+n);
    l=r=-1;
    for(int i=0; i<n; i++){
        if(a[i]!=b[i]) continue;
        if(l==-1) l=i;
        r=i;
        x=a[i];
    }
    if(l==-1){
        cout << "Yes\n";
        for(int i=0; i<n; i++) cout << b[i] << " ";
        return 0;
    }
    p=q=-1;
    for(int i=0; i<n; i++){
        if(a[i]==x || b[i]==x){
            if(p==-1) p=i;
            q=i;
        }
    }
    int i=0,j=l;
    while(i<p && j<=r) swap(b[i++],b[j++]);
    i=q+1;
    while(i<n && j<=r) swap(b[i++],b[j++]);
    for(int i=0; i<n; i++){
        if(a[i]==b[i]){
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    for(int i=0; i<n; i++) cout << b[i] << " ";
    return 0;
}
