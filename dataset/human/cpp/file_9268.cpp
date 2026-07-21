#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <set>
#include <math.h>
#include <map>
#include <stack>
using namespace std;
static const int INF = 1e9+7;
// 型定義
typedef long long ll;
typedef pair<ll, ll> P;

#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, a, b) for (int i =a; i < b; i++)
#define all(a) a.begin(), a.end()
#define PI 3.14159265359

int main(){
    int n, m; cin >> n >> m;

    const int nmax = 50;
    char A[nmax][nmax], B[nmax][nmax];

    rep(i,n){
        rep(j,n){
            cin >> A[i][j];
        }
    }

    rep(i,m){
        rep(j,m){
            cin >> B[i][j];
        }
    }

    bool exist = false;

    rep(i, n){
        rep(j, n){
            if(i + m -1 >= n or j + m - 1 >= n) continue;

            bool match = true;
            for(int y=0; y<m; y++){
                for(int x=0; x<m; x++){
                    if(A[i+y][j+x] != B[y][x]) match = false;
                }
            }
            if(match) exist = true;
        }
    }

    if(exist){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}
