//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
//#pragma GCC target ("avx,avx2,tune=native")
//#pragma GCC optimization ("unroll-loops")
#include "bits/stdc++.h"

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#include <ext/rope>

using namespace __gnu_pbds; 
using namespace __gnu_cxx;
using namespace std;
using ll = long long;

#define eb emplace_back
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define len(v) ((int)v.size())
#define all(v) v.begin(), v.end()
#define precision(n) fixed<<setprecision(n)

#ifdef LOCAL
    #include "debug.h"
#else
    #define debug(...) 42
#endif

void io(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);    
    #ifdef LOCAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("output.txt","w",stderr);
    #endif
}
template<typename T> using oset = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update >;
template<typename T> using MinPriorityQueue = priority_queue <T, vector <T>, greater <T> >;
template<typename T> void done(T ans) {cout << ans << "\n"; exit(0);}

auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937_64 mt(seed);

clock_t time_p=clock();
void printTime(){
    time_p=clock()-time_p;
    cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
}

template <typename A>
istream& operator>>(istream& input,vector<A>& x) {
  for(auto& i:x)
    input>>i;
  return input;
}
 
template<typename A>
ostream& operator<<(ostream& output,vector<A>& x) {
  for(auto& i:x)
    output<<i<<' ';
  return output;
}


const int N = 2e5 + 5;
const int mod = 1e9 + 7;

int main() {
    io();
    int n;
    cin >> n;
    n = n * 2;
    string s;
    cin >> s;
    int arr[n];
    for(int i = 0; i < n; i++) {
        if(s[i] == 'W')
            arr[i] = 0 ;
        else
            arr[i] = 1 ;
    }
    long long ans = 1ll ;
    long long moves = 0 ;
    if(arr[0] == 0)
        return cout << 0 << "\n", 0;

    for(int i = 0 ; i < n; ++i) {
        if((arr[i] + moves) % 2 != 0)
            moves++ ;
        else {
            ans = (ans * moves) % mod ;
            ans %= mod ;
            moves-- ;
        }
        if(moves > n / 2 || moves < 0)
            return cout << 0 << "\n" , 0 ;
    }
    if(moves != 0)
        return cout << 0 << "\n" , 0 ;
    long long fact = 1ll ;
    for(int i = 2 ; i <= n / 2 ; ++i) {
        fact = (fact * i) % mod ;
        fact %= mod ;
    }
    ans = (ans * fact) % mod ;
    ans %= mod ;
    return cout << ans << "\n" , 0;
}
