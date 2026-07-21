#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> p2;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,r;
    cin>>n>>r;
    if(n>10)
    cout<<r;
    else
    cout<<r+100*(10-n);
}
