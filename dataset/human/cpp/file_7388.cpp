#include<iostream>
#include<cstdlib>
using namespace std;

typedef long long ll;


int main(){
    ll N; 
    cin >> N;
    ll a[N];
    ll tmp;
    cin >> a[0];
    for(ll i=1; i<N; i++){
        cin >> tmp;
        a[i] = a[i-1] + tmp;
    }
    ll ans;
    ans = 2000000000;
    for(ll i=1; i<N; i++){
        ans = min(ans, abs(a[N-1]-2*a[i-1]));
    }
    cout << ans << endl;
}
