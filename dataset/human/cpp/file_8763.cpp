#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> l_l;
typedef vector<ll> vel;
typedef vector<int> vei;
typedef vector<char> vec;
typedef vector<string> ves;
typedef vector<vector<int>> ve_vei;
typedef vector<vector<char>> ve_vec;
typedef vector<vector<string>> ve_ves;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<(int)(n);i++)
#define rep2(i,n) for(int i=2;i<(int)(n);i++)
#define fs first
#define sc second
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define mod (1000000007)

int main(){
    int n,m; cin >> n >> m;
    ves a(n), b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];

    rep(l,n-m+1){
        rep(k,n-m+1){
            bool xcheck = true;
            bool ycheck = true;
            rep(i,m) {
                rep(j,m){
                    if(b[i][j] != a[i+l][j+k]) xcheck = false;
                    if(b[i][j] != a[i+k][j+l]) ycheck = false;
                }
            }
        if(xcheck or ycheck) {
            cout << "Yes" << endl;
            return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;

}
