#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    ll sum = 0;
    int minuscount = 0;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        if (a[i] < 0) minuscount++;
        a[i] = a[i] < 0 ? -a[i] : a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end());
    if (minuscount % 2 == 0) {
        cout << sum << endl;
    } else {
        sum -= 2 * a[0];
        cout << sum << endl;
    }
    return 0;
}
