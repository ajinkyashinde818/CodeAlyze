#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios_base:: sync_with_stdio(false);
    ll n,r;cin>>n>>r;
    if(n>=10)return cout<<r , 0;
    cout<< r + 100*(10-n);
}
