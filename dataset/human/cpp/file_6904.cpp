#include <bits/stdc++.h>
using namespace std;

typedef long lint;
typedef long long llint;
typedef pair<int, int> pint;
typedef pair<long long, long long> pllint;
typedef tuple<long long, long long, long long> tllint;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const llint INF = 1<<21;
// static const llint MOD = 1e9 + 7;

bool compPair(const pint& arg1, const pint& arg2) { return arg1.first > arg2.first; }
bool compTuple(const tllint& arg1, const tllint& arg2) { return get<2>(arg1) > get<2>(arg2); }
template<class T> bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main(void) {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);
    for(int in=0;in<n;++in) {
        cin >> a[in];
    }
    for(int in=0;in<n;++in) {
        cin >> b[in];
    }

    int j = 0, bef = -1;
    for(int in=0;in<n;++in) {
        if(bef!=a[in]) j = 0;
        if(a[in]==b[in]) {
            for(;j<n;++j) {
                if(a[j]!=a[in]&&b[j]!=a[in]) {
                    swap(b[in], b[j]);
                    break;
                }
            }
            if(a[in]==b[in]) {
                cout << "No" << endl;
                return 0;
            }
        }
        bef = a[in];
    }
    
    cout << "Yes" << endl;
    for(int in=0;in<n;++in) {
        if(in) cout << " ";
        cout << b[in];
    }
    cout << endl;
    return 0;
}
