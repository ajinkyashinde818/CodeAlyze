#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
using vvll = vector< vector<ll> >;
using vll = vector<ll> ;    
using pll = pair<ll, ll> ;
 
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define I insert
#define ar array
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) ((long long)x.size())
 
 
template<typename T> void umin(T& a,T b){a = min(a,b);}
template<typename T> void umax(T& a,T b){a = max(a,b);}
 
const ll maxs = 1e6+5;
const ll lmaxs = 20;
ll mod = 1e9+7;
ll oo = 1e15;
 
ll fast(ll x,ll y){
    ll res=1;
    while(y){
        if(y&1)
            res = (res*x)%mod;
        x = (x*x)%mod;
        y >>= 1;
    }
    return res;
}
 
ll inv(ll n){
    return fast(n,mod-2);
}
 
void pre(){
    
    
 
}




void solve(){    

    int n;
    cin >> n;
    int a[n+1], b[n+1];
    vector<int> ma(n+1,0) , mb(n+1,0);
    for(int i=0;i<n;i++){
        cin >> a[i];
        ma[a[i]]++;
    } 
    for(int i=0;i<n;i++){
        cin >> b[i];
        mb[b[i]]++;
    }

    for(int i=0;i<=n;i++){
        if(ma[i] + mb[i] > n){
            cout << "No";
            return;
        }
    }
    reverse(b,b+n);
    int l=0,r=n-1;
    for(int i=0;i<n;i++){
        if(a[i] == b[i]){
            if(b[l] != a[i] and b[i] != a[l]){
                swap(b[i],b[l]);
                l++;
            }else if(b[r] != a[i] and a[r] != b[i]){
                swap(b[i],b[r]);
                r--;
            }else{
                cout << "No\n";
                return;
            }
        }
    }   
    for(int i=0;i<n;i++){
        if(a[i] == b[i]){
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
    for(int i=0;i<n;i++){
        cout << b[i] << " ";
    }

}
 
int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input00.txt","r",stdin);
    freopen("output00.txt","w",stdout);
    #endif
    IOS;
    pre();
    ll T = 1;
    //cin >> T;
    while(T--){
        static int i=1;
        //cout << "Case #" << i << ": ";
        i++;
        solve();   
    }
    return 0;
}
