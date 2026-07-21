#include <bits/stdc++.h>
#include <string>
#include <cmath>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<ll> vll;
 
#define all(v) v.begin(),v.end()
#define test() int t;cin>>t;while(t--) 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ff first
#define ss second
const ll mod = (ll)1e9 + 7;
const ll INF = -(ll)1e10;

int main()
{
    int n;
    cin>>n;
    vi a(n), b(n), cnta(n+1), cntb(n+1);
    for(int i = 0; i<n; i++)
    {
        cin>>a[i];
        cnta[a[i]]++;
    }
    for(int i =0; i<n; i++)
    {
        cin>>b[n-i-1];
        cntb[b[n-i-1]]++;
    }
    int start = -1, end = n, idx = 0;
    while(true)
    {
        while(idx<n && a[idx]!=b[idx])idx++;
        start = idx;
        while(idx<n && a[idx]==b[idx])idx++;
        end = idx;
        break;        
    }
    if(start == n)
    {
        cout<<"Yes"<<endl;
        for(int x : b)cout<<x<<" ";
        cout<<endl;
        return(0);
    }
    if(cnta[a[start]]>n-cntb[b[start]])
    {
        cout<<"No"<<endl;
        return(0);
    }
    int curr = start;
    for(int  i = 0; i<n; i++)
    {
        if(b[i]!=b[curr] && a[i]!=a[start])
        {
            swap(b[i], b[curr++]);
            if(curr==end)break;
        }
    }
    cout<<"Yes"<<endl;
    for( int x : b)cout<<x<<" ";
    cout<<endl;
}
