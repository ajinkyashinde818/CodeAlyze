#include <bits/stdc++.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>

#include <bitset>
#include <cassert>
#include <queue>
#include <random>
#include <stack>
#include <iomanip>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n;i++)
#define repf(i, a, b) for (int i = (int)a; i < (int)b;i++)
#define repv(x, arr) for (auto& x:arr)
#define all(v) (v).begin(), (v).end()
#define vec(name, num) vector<ll> name((num), 0);
#define mp(a,b) make_pair(a,b)
#define op(i) cout << (i) << endl;
#define F first
#define S second

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;

const ll mod = 1e9 + 7;


int main(){
    int N, M;
    cin >> N >> M;
    vector<string> A(N);
    vector<string> B(M);
    rep(i,N){
        cin >> A[i];
    }
    rep(i,M){
        cin >> B[i];
    }
    rep(i,N-M+1){
        rep(j,N-M+1){
            bool flag = true;
            rep(x,M){
                rep(y,M){
                    if (A[i+x][j+y]!=B[x][y]){
                        flag = false;
                    }
                }
            }
            if (flag){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}
