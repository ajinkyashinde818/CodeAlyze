#include <bits/stdc++.h>
typedef   long long int ll;
using namespace std;
int main ()
{
     ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    ll n,r;cin>>n>>r;
    if (n>=10) cout<<r<<endl;
    else {
        cout<<100*(10-n)+r<<endl;
    }
}
