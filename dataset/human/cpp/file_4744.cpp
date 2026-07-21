#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1e6 + 7;
const int INF = 0x3f3f3f3f;

int a[maxn];

int main() {
    int n,r;
    while(cin >> n >> r) {
        if(n < 10) cout << r + 100 * (10 - n) << endl;
        else cout << r << endl;
    }
    return 0;
}
