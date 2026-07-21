#include<iostream>
using namespace std;

typedef long long ll;

static const ll INF=1000000000000000;

int main(){
    int N;
    cin >> N;
    ll a[N];
    for(int i=0;i<N;i++) cin >> a[i];
    for(int i=1;i<N;i++){
        a[i]+=a[i-1];
    }
    ll ans=INF;
    for(int i=0;i<N-1;i++){
        ans=min(ans,abs(a[i]-(a[N-1]-a[i])));
    }
    cout << ans << endl;
}
