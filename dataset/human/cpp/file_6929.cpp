#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    int n; cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = n-1; i >= 0; i--) cin >> b[i];
    int dst = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) continue;
        while (dst < n && (a[dst] == a[i] || b[dst] == b[i])) dst++;
        if (dst == n) { cout << "No\n"; return 0; }
        swap(b[dst], b[i]);
        dst++;
    }
    cout << "Yes\n";
    for (int e : b) cout << e << " ";
    cout << endl;
}
