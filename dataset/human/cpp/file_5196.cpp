#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1e9+7;
const int INF=1e9;
const ll LINF=(ll)1e18;

int main(){
    int n,r;
    cin>>n>>r;
    if(n>=10)cout<<r<<endl;
    else cout<<r+100*(10-n)<<endl;
}
