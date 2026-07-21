#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int l, int r)
{
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}
  
#define int long long 
#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define precise(x) fixed << setprecision(x) 

const int MOD = 1e9+7;

int mod_pow(int a,int b,int M = MOD)
{
    int res = 1;
    
    while(b)
    {
        if(b&1) res=(res*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    
    return res;
}

const int N = 2e5 + 10;
vi ga[N],gb[N];

void solve()
{
   int n;
    cin >> n;
    
    int a[n];
    f(i,n) cin >> a[i];
    
    int b[n];
    f(i,n) cin >> b[i];
    
    f(i,n) ga[a[i]].pb(i);
    f(i,n) gb[b[i]].pb(i);
    
    vi res(n,-1);
    
    for(int i=1;i<=n;i++)
    {
        if((int)ga[i].size() + (int)gb[i].size() > n)
        {
            cout <<"No\n";
            return;
        }
    }
    
    vector<pii> go;
    
    for(int i=1;i<=n;i++)
        go.pb({ga[i].size(),i});
        
    sort(go.begin(),go.end());
    reverse(go.begin(),go.end());
    
    set<pii> ind;
    f(i,n) ind.insert({ga[a[i]].size(),i});
    
    for(auto v : go)     
    {
        int i = v.S;
        
        int need = (int)gb[i].size();
        
        vector<pii> rem;
        
        for(auto x : ind)
        {
            if(need == 0) break;
          
            if(a[x.S] == i) continue;
            else 
            {
                res[x.S] = i;
                rem.pb(x);
                need--;
            }
        }
        
        for(auto x : rem) ind.erase(x);
    }
    
    cout <<"Yes\n";
    
    for(auto x : res) cout << x << ' ';
    
}

signed main()
{
    fast;
    
    int t = 1;
    
//    cin >> t;
    
    while(t--)
        
    solve();
}
