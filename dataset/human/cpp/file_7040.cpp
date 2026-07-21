#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <map>
#include <set>
#include <iostream>
#include <sstream>
#include <numeric>
#include <cctype>
#include <bitset>
#include <cassert>

using namespace std;

const int N = 4e5 + 10;
int n, a[N], b[N], cnta[N], cntb[N], ans[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnta[a[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        cntb[b[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        if (cnta[i] + cntb[i] > n) {
            cout << "No" << endl;
            return 0;
        }
    }
    for (int i = 1; i <= n; i++) ans[i] = b[n - i + 1];
    for (int i = 1; i <= n;i++) {
        if (ans[i] == a[i]) {
            int pt = 0;
            while (i + pt <= n && ans[i + pt] == a[i + pt]) pt++;
            pt--;
            for (int j = 1; j <= n; j++) {
                if (a[j] != a[i] && ans[j] != ans[i]) {
                    swap(ans[j], ans[i + pt]);
                    pt--;
                    if (pt < 0) break;
                }
            }
        }
    }
    cout << "Yes" << endl;
    for (int i = 1; i < n; i++) cout << ans[i] << " ";
    cout << ans[n] << endl;
    return 0;
}
