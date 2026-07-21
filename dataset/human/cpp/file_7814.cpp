#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void){
    ll N;
    cin>>N;
    
    vector<ll> a(N);
    ll sunuke=0;
    for(int i=0;i<N;i++){
        cin>>a[i];
        sunuke+=a[i];
    }
    
    ll arai=0;
    ll ans=1e15;
    for(int i=0;i<N-1;i++){
        arai+=a[i];
        sunuke-=a[i];
        ans=min(ans,abs(arai-sunuke));
    }
    
    cout<<ans<<endl;
    
}
