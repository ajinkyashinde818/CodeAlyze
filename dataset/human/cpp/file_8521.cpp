#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>

#ifdef PRINTERS
#include "printers.hpp"
using namespace printers;
#define tr(a)        cout<<a<<endl;
#else
#define tr(a)    
#endif

#define ll          long long
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)    for(int i=a;i<b;i++)
using namespace std;

void solve(){
    int N,M;
    cin>>N>>M;
    string s[N];
    rep(i,0,N)cin>>s[i];
    string t[M];
    rep(i,0,M)cin>>t[i];
    rep(i,0,N-M+1){
        rep(j,0,N-M+1){
            bool good=1;
            rep(k,i,i+M){
                rep(l,j,j+M){
                    if(s[k][l]!=t[k-i][l-j])good=0;
                }
            }
            if(good){
                cout<<"Yes\n";
                return;
            }
        }
    }
    cout<<"No\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
//    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
