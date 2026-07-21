#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <bitset>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    int n, r;
    cin >> n >> r;

    int ans;
    if (n >= 10) ans = r;
    else ans = r+100*(10-n);

    cout << ans << endl;
}
