//{{{
#include<algorithm>
#include<cmath>
#include<deque>
#include<fstream>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<random>
#include<set>
#include<sstream>
#include<sys/time.h>
#include<unordered_map>
#include<unordered_set>
#include<vector>
using ll = long long;
enum : int { M = (int)1e9 + 7 };
enum : ll { MLL = (ll)1e18L + 9 };
using namespace std;
#ifdef LOCAL
#include"rprint2.hpp"
#else
#define FUNC(name) template <ostream& out = cout, class... T> void name(T&&...){ }
FUNC(printde) FUNC(printdbe) FUNC(printdwe) FUNC(printdu);
#endif
template <template <class T, class = std::allocator<T>> class V, class E>
istream& operator >> (istream& in, V<E>& v){ for(auto& e : v){ in >> e; } return in; }
//}}}

// mint
template <int M>
struct ModInt {
    int num;
    ModInt(): num(0){ }
    ModInt(int num): num(num){ }
    operator int () const { return num; }
    // template <class T> ModInt operator + (T n) const { n += num; return n >= M ? n - M : n; }
    // template <class T> ModInt operator - (T n) const { n = num - n; return n < 0 ? n + M : n; }
    template <class T> ModInt operator + (T n) const { auto ret = num + n; return ret >= M ? ret - M : ret; }
    template <class T> ModInt operator - (T n) const { auto ret = num - n; return ret < 0 ? ret + M : ret; }
    // template <class T> ModInt operator + (T n) const { return (num + n) % M; }
    // template <class T> ModInt operator - (T n) const { return (num - n + M) % M; }
    template <class T> ModInt operator * (T n) const { return (ll)num * n % M; }
    template <class T> ModInt operator / (T n) const { return (ll)num * modInv(ModInt(n)) % M; }
    template <class T> ModInt operator >> (T n) const { return num >> n; }
    template <class T> ModInt operator << (T n) const { return ((ll)num << n) % M; }
    template <class T> ModInt operator | (T n) const { return num | n; }
    template <class T> ModInt operator & (T n) const { return num & n; }
    template <class T> bool operator < (T n) const { return num < n; }
    template <class T> bool operator > (T n) const { return num > n; }
    template <class T> bool operator <= (T n) const { return num <= n; }
    template <class T> bool operator >= (T n) const { return num >= n; }
    template <class T> bool operator == (T n) const { return num == n; }
    template <class T> bool operator != (T n) const { return num != n; }
    ModInt operator ++ (int){ int ret = num; num = num == M + 1 ? 0 : num + 1; return ret; }
    ModInt operator -- (int){ int ret = num; num = num == 0 ? M - 1 : num - 1; return ret; }
    ModInt operator ++ (){ return num = num == M + 1 ? 0 : num + 1; }
    ModInt operator -- (){ return num = num == 0 ? M - 1 : num - 1; }
    // ModInt operator ++ (int){ int ret = num; num = (num + 1) % M; return ret; }
    // ModInt operator -- (int){ int ret = num; num = (num - 1 + M) % M; return ret; }
    // ModInt operator ++ (){ return num = (num + 1) % M; }
    // ModInt operator -- (){ return num = (num - 1 + M) % M; }
    template <class T> ModInt operator += (T n){ num += n; return num = num >= M ? num - M : num; }
    template <class T> ModInt operator -= (T n){ num -= n; return num = num < 0 ? num + M : num; }
    // template <class T> ModInt operator += (T n){ auto ret = num + n; return num = ret >= M ? ret - M : ret; }
    // template <class T> ModInt operator -= (T n){ auto ret = num - n; return num = ret < 0 ? ret + M : ret; }
    // template <class T> ModInt operator += (T n){ return num = (num + n) % M; }
    // template <class T> ModInt operator -= (T n){ return num = (num - n) % M; }
    template <class T> ModInt operator *= (T n){ return num = (ll)num * n % M; }
    template <class T> ModInt operator /= (T n){ return num = (ll)num * modInv(n) % M; }
    template <class T> ModInt operator >>= (T n){ return num = num >> n; }
    template <class T> ModInt operator <<= (T n){ return num = ((ll)num << n) % M; }
    friend ModInt modPow(ModInt base, ModInt ex);
    static vector<ModInt> mFacts, mInvFacts;
    friend ModInt modFact(ModInt n){ return mFacts[n.num]; }
    friend ModInt modInvFact(ModInt n){ return mInvFacts[n.num]; }
    friend ModInt modInv(ModInt n){ return modPow(n, M - 2); }
    friend ModInt modC(ModInt n, ModInt k){ return modFact(n) * modInvFact(k) * modInvFact(n - k); }
    static void init(int n){
        mFacts.resize(n + 1);
        mInvFacts.resize(n + 1);
        mFacts[0] = 1;
        for(int i = 1; i <= n; i++){
            mFacts[i] = mFacts[i - 1] * i;
        }
        mInvFacts[n] = modInv(mFacts[n]);
        for(int i = n - 1; i >= 0; i--){
            mInvFacts[i] = mInvFacts[i + 1] * (i + 1);
        }
    }
    friend istream& operator >> (istream& in, ModInt& e){ return in >> e.num; }
    friend ostream& operator << (ostream& out, const ModInt& e) { return out << e.num; }
};
template <int M>
vector<ModInt<M>> ModInt<M>::mFacts;
template <int M>
vector<ModInt<M>> ModInt<M>::mInvFacts;
// using mint = ModInt<998244353>;
using mint = ModInt<(int)M>;
mint modPow(mint base, mint ex){
    mint ret = 1;
    while(ex.num){
        if(ex.num & 1){ ret = ret * base; }
        ex >>= 1;
        base = base * base;
    }
    return ret;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    int n; cin >> n;
    string s; cin >> s;
    // int n2 = n * 2 - 1;
    mint ans = 1;
    vector<int> rs(2 * n, -1);
    int cnt = 0;
    for(int i = 2 * n - 1; i >= 0; i--){
        if((s[i] == 'B') ^ (i % 2 == 0)){
            cnt++;
        }else{
            rs[i] = cnt;
        }
    }
    if(cnt != n){
        cout << 0 << '\n';
        return 0;
    }
    printde(rs);
    cnt = 0;
    for(int i = 2 * n - 1; i >= 0; i--){
        if(rs[i] == -1){ continue; }
        ans *= rs[i] - cnt;
        cnt++;
    }
    // while(n2 > 0){
    //     ans *= n2;
    //     n2 -= 2;
    // }
    for(int i = 2; i <= n; i++){
        ans *= i;
    }
    cout << ans << '\n';
}
