#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll n,k;
    cin>>n>>k;
    if(n>=10)
        cout<<k<<endl;
    else
        cout<<k+100*(10-n)<<endl;
    return 0;
}
