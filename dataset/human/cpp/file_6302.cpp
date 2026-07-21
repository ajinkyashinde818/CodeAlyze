#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//#define eps 1e-8
//#define eq(x,y) (fabs((x)-(y)) < eps)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int>pii;
const int mod = 1e9+7;
long double PI = acosl(-1);
const ll infl = 3e18+100;
const int inf = 1e8+100;
const int nmax = 1e5+5;
const int MAXLG = log2(nmax)+1;
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
//typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ost;

void NA(){
    cout<<"0";
    exit(0);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int>typ(2*n);
    if(s[0]=='W' or s[2*n-1]=='W') NA();

    for(int i=1; i<2*n; i++){
        if(s[i]==s[i-1]) typ[i] = typ[i-1] ^ 1;
        else typ[i] = typ[i-1];
    }
    if(typ[2*n-1]==0) NA();
    int pref1=0, pref0=1;
    ll ans = 1;
    int sam = 0;
    for(int i=1; i<2*n; i++){
        if(typ[i]){
            int opshon = pref0-pref1;
            ans = (ans * max(0, opshon))%mod;
            sam++;
        }
        if(typ[i]) pref1++;
        else pref0++;
    }
    if(sam!=n) NA();
    for(int i=1; i<=n; i++) ans = (ans * i) % mod;
    cout<<ans<<endl;

}
