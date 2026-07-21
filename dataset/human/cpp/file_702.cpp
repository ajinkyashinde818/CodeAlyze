#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int a,b,c,n;
    cin>>a>>b>>c>>n;
    ll ans=0;
    for (int i=0;a*i<=n;++i){
        for (int j=0;b*j+a*i<=n;++j){
            int k=n-a*i-b*j;
            if (k%c!=0) continue;
            ++ans;
        }
    }
    cout<<ans<<endl;
    return 0;
}
