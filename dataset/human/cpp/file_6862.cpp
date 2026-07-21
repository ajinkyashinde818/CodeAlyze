#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<ll, ll>;
const long double PI = acos(-1.0L);
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }

int n;

int main() {
    cin >> n;
    vector<int> avec(n, 0);
    vector<int> bvec(n, 0);
    for(int i = 0; i < n; ++i) cin >> avec[i];
    for(int i = 0; i < n; ++i) cin >> bvec[i];

    map<int, int> acnt;
    map<int, int> bcnt;
    for(int i = 0; i < n; ++i) {
        acnt[avec[i]]++;
        bcnt[bvec[i]]++;
    }

    for(int i = 0; i < n; ++i) {
        if(n-acnt[avec[i]] < bcnt[avec[i]]) {
            cout << "No" << endl;
            return 0;
        }
    }

    sort(bvec.begin(), bvec.end(), greater<int>());
    for(int i = 0; i < n; ++i) {
        if(avec[i] == bvec[i]) {
            for(int j = 0; j < i; ++j) {
                if(avec[i] != bvec[j] && avec[j] != bvec[i]) {
                    swap(bvec[i], bvec[j]);
                    break;
                }
            }
        }
    }

    bool flg = true;
    for(int i = 0; i < n; ++i) {
        if(avec[i] == bvec[i]) {
            for(int j = 0; j < n; ++j) {
                if(i == j) continue;
                if(avec[i] != bvec[j] && avec[j] != bvec[i]) {
                    swap(bvec[i], bvec[j]);
                    break;
                }
            }
        }
    }

    for(int i = 0; i < n; ++i) {
        if(avec[i] == bvec[i]) flg = false;
    }

    if(flg) {
        cout << "Yes" << endl;
        for(int i = 0; i < n; ++i) {
            if(i == n-1) cout << bvec[i] << endl;
            else cout << bvec[i] << " ";
        }
    }else cout << "No" << endl;
}
