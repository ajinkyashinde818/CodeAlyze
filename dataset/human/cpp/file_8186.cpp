#include <iostream>
using namespace std;
typedef long long ll;
int main(void){
    ll n,tot=0, ans=1LL<<60;
    cin>>n;
    ll s[n];
    for(int i=0;i<n;i++){
        cin>>s[i];
        tot+=s[i];
    }
    for(int i=0;i<n-1;i++){
        tot-=2*s[i];
        ans=min(ans,abs(tot));
    }
    cout<<ans<<endl;
}
