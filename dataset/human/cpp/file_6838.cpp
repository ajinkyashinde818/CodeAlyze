#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;

int a[MAXN], b[MAXN];
int main() {
    int n;
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        m[a[i]]++;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        m[b[i]]++;
    }
    for (auto it : m) {
        if (it.second > n) {
            cout << "No\n";
            return 0;
        }
    }
    reverse(b, b + n);
    int l = 0, r = n - 1;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            if(a[i] != b[l] and a[l] != b[i]) {
                swap(b[l], b[i]);
                l ++;
            }
            else {
                swap(b[r], b[i]);
                r --;
            }
        }
    }
    cout << "Yes\n";
    for (int i = 0; i < n; i++) cout << b[i] << " ";
    cout << endl;
}
