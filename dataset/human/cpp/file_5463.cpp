#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, rating;
    cin >> n >> rating;
    if (n >= 10) {
        cout << rating << endl;
    } else {
        cout << rating + 100 * (10 - n) << endl;
    }
}
