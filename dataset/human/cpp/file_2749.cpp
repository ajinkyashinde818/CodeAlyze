#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    long long t,x,ans=0,cnt=0,mi=1e9+7;
    cin>>t;
    while(t--){
        cin>>x;
        if(x<0) {
            x*=-1;
            cnt++;
        }
        mi=min(mi,x);
        ans+=x;
    }
    if(cnt&1) ans-=2*mi;
    cout<<ans;
}
