#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const ll mod = 1e9+7;
struct mint {
    ll x;
    mint(ll x=0):x((x%mod+mod)%mod){}
    mint& operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += mod-a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const mint a) {
        (x *= a.x) %= mod;
        return *this;
    }
    mint operator+(const mint a) const {
        mint res(*this);
        return res+=a;
    }
    mint operator-(const mint a) const {
        mint res(*this);
        return res-=a;
    }
    mint operator*(const mint a) const {
        mint res(*this);
        return res*=a;
    }
    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }
    // for prime mod
    mint inv() const {
        return pow(mod-2);
    }
    mint& operator/=(const mint a) {
        return (*this) *= a.inv();
    }
    mint operator/(const mint a) const {
        mint res(*this);
        return res/=a;
    }
};

int main(){
    int N;
    string S;
    cin >> N >> S;
    mint ans = 1;
    vector<bool> is_left(2*N,false);
    is_left[0] = true;
    for(int i=1;i<2*N;i++){
        if(S[i]!=S[i-1]) is_left[i] = is_left[i-1];
        else is_left[i] = !is_left[i-1];
    }
    ll cnt = 0;
    for(ll i=0;i<2*N;i++){
        if(is_left[i]) cnt++;
        else ans *= 2*cnt-i;
    }
    mint fact = 1;
    for(ll i=2;i<=N;i++) fact *= i;
    cerr << cnt << endl;
    if(S[0]=='W' || S[2*N-1]=='W' || cnt!=N) cout << 0 << endl;
    else cout << (ans*fact).x << endl;
}
