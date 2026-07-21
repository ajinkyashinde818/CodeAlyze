#include<iostream>
#include<algorithm>
#include<climits>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<string>
#include<cstring>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mod 1000000007LL
#define eps 0.0001

#define rep(i, n) for(i = 0;i < n;++i)
#define rep1(i, n) for(i = 1;i < n;++i)
#define pri(x) cout << (x) << "\n"
#define pri2(x, y) cout << (x) << " " << (y) << "\n"
#define pri3(x, y, z) cout << (x) << " " << (y) << " " << (z) << "\n"


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    // ---------------------
    // コーディング開始
    // ---------------------

    int n,m;

    cin >> n >> m;
    int i;
    string a[n],b[m];
    rep(i,n){
        cin >> a[i];
    }
    rep(i,m){
        cin >> b[i];
    }

    int j,k;
    rep (i,n-m+1){
        rep(j,n-m+1){
           rep(k,n){
                if (a[i+k].substr(j,m)==b[k]){
                    if(k==m-1){
                        pri("Yes") ;
                        return 0;
                    }
                } else {
                    break; 
                }
           }
        }
    }
    pri("No") ;
    return 0;
}
