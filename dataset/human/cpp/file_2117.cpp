#include <bits/stdc++.h>
using namespace std;
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
os << "[ "; for(auto v : V) os << v << " "; return os << "]";}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")";}

// #define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cout << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...) 1
#endif
typedef long long ll;
typedef double ld;
#define pll pair<ll,ll>
#define pb push_back
#define mp(x, y) make_pair((x), (y))
#define F first
#define S second
#define I insert
#define vll vector<ll>
#define vpll vector<pll>
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll)(x).size()
   
const ll Mod = 1e9 + 7;

int main(){
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    int n; cin >> n;
    ll A[n+1] , sum = 0 , Count = 0;
    for(int i= 1 ;i <= n ; i++){
        cin >> A[i];
        sum += abs(A[i]);
        if(A[i] < 0)
            Count++;
    }
    if(Count%2 == 0){
        cout << sum << endl;
        return 0;
    }
    
    ll mn1 = Mod , mn2 = Mod;
    for(int i = 1 ; i <= n ; i++){
        if(A[i] >= 0)
            mn1 = min(mn1 , A[i]);
        else
            mn2 = min(mn2 , abs(A[i]));
    }
    
    cout << sum - 2*min(mn1 , mn2) << endl;
    
   return 0;
}
