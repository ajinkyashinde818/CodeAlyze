#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
 
using namespace __gnu_pbds;
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int sll;
typedef long double ld;
#define A 1000000007ll
#define D 100000000000000ll
#define B 998244353ll
#define C 1000000000000000000ll
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define oset tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> 
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define mxe(v) *max_element(v.begin(),v.end())
#define mne(v) *min_element(v.begin(),v.end())
#define rev(v) reverse(v.begin(),v.end())
#define sor(v) sort(v.begin(),v.end())
#define sorrev(v) sort(v.begin(),v.end(),greater<ll>())
#define uni(v) unique(v.begin(),v.end())
#define bs binary_search
#define lb(v,x) lower_bound(v.begin(),v.end(),x)-v.begin()
#define ub(v,x) upper_bound(v.begin(),v.end(),x)-v.begin()
#define ve vector
#define br break
#define PI acos(-1)
#define subt cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n" 

int main() 
{
    FAST;
    ll n;
    cin>>n;
    ve<ll> a(n),b(n);
    for(ll i=0;i<n;i++)
        cin>>a[i];
    for(ll i=0;i<n;i++)
        cin>>b[i];
    ll p=0,q=0;
    while(p<n)
    {
        if(a[p]==b[p])
        {
            ll co=0;
            while(co<n && (a[q]==a[p] || b[q]==a[p]))
            {
                co++;
                q=(q+1)%n;
            }
            if(co==n)
            {
                cout<<"No";
                return 0;  
            }
            swap(b[p],b[q]);
        }
        p++;
    }
    cout<<"Yes\n";
    for(auto i:b)
        cout<<i<<' ';
    subt;
    return 0;
}
