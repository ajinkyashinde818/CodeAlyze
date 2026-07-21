#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
using namespace std;

int main(){
    ll n,r;
    cin>>n>>r;
    ll ans;
    if(n>=10){
        ans=r;
    }else{
        ans=r+100*(10-n);
    }
    cout<<ans<<endl;
    return 0;
}
