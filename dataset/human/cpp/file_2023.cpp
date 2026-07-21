//#define _GLIBCXX_DEBUG
    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    typedef pair<int, int> pii;
    typedef map<int, int> mii;
    typedef map<char,int> mci;
    typedef vector<int> vi;
    typedef vector<vi> vvi;
    typedef vector<ll> vll;
    typedef vector<pair<int,int>> vii;
    typedef vector<char> vc;
    typedef vector<vc> vcc;
    #define all(x) (x).begin(), (x).end()
    #define rall(x) (x).rbegin(), (x).rend()
    #define pb push_back
    #define mp make_pair
    #define F first
    #define S second
    #define in insert
    #define sz(v) v.size()
    #define mina(a,b) (a)=min((a),(b));
    #define maxa(a,b) (a)=max((a),(b));
    const int INF = 1e9 + 5;
    
    void solve(){
        int n; cin>>n;
        vll v(n);
        int mi=INF;
        int cnt=0;
        for(int i = 0; i < n; i++) {
            cin>>v[i];
            if(v[i]<0) cnt++;
            if(abs(v[i])<abs(mi)) mi=v[i];
        }
        ll sum=0;
        for(int i = 0; i < n; i++) sum+=abs(v[i]);
        if(cnt%2==0) cout<<sum;
        else cout<<sum-2*abs(mi);
        //cout<<sum;

    }
    int main(){
        int T=1;
        //cin>>T;
        for(int i = 0; i < T; i++) solve(); 
    }
