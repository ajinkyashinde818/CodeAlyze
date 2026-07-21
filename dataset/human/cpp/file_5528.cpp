#include<bits/stdc++.h>

using namespace std;
using ll = long long;

template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;
template <class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template <class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_V(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl;
#define DEBUG_M(v) cerr<<#v<<endl;for(int i=0;i<v.size();i++){for(int j=0;j<v[i].size();j++) {cerr<<v[i][j]<<" ";}cerr<<endl;}

int main() {
    int n, r;
    cin>>n>>r;
    if(n>=10){
        cout<<r<<endl;
    }else{
        cout<<r + 100*(10-n)<<endl;
    }

    return 0;
}
