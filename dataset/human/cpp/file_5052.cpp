#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const ll INF = 1<<21;
// static const ll MOD = 1e9 + 7;

bool compPair(const pair<int, int>& arg1, const pair<int, int>& arg2) {
    return arg1.first > arg2.first;
}

int main(void) {
    int n, r;
    cin >> n >> r;

    if(n>=10) {
        cout << r << endl;
    }
    else {
        cout << r+100*(10-n) << endl;
    }
    return 0;
}
