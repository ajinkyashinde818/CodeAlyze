#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = 1e9;
int n;
vector<long long> a(100100, 0);

int main() {
    cin >> n;
    int mcnt = 0;
    int mno = 0;
    int mmm = INF;
    for(int i = 0; i < n; ++i) {
        cin >> a.at(i);
        if(a.at(i) < 0) mcnt++;
        if(abs(a.at(i) - 0) < mmm) {
            mno = i;
            mmm = abs(a.at(i) - 0);
        }
    }

    long long ans = 0;
    for(int i = 0; i < n; ++i) {
        ans += abs(a.at(i) - 0);
    }

    if(mcnt % 2 != 0) {
        ans -= abs(a.at(mno) - 0) * 2;
    }

    cout << ans << endl;
}
