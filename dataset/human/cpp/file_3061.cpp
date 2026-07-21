#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
using namespace std;

int main() {
    int n;
    int m = 0;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] < 0) m += 1;
        a[i] = abs(a[i]);
    }

    sort(a.begin(), a.end());
    long long sum = 0;
    for(int i = 0; i < n; i++) {
        sum += a[i];
    }
    if(m % 2 == 1) {
        long long ans = sum - 2 * a[0];
        cout << ans << endl;
    } else {
        long long ans = sum;
        cout << ans << endl;
    }
}
