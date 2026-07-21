#include <iostream>
using namespace std;

typedef long long ll;

ll arr[200010];
ll psum[200010];
int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    psum[0] = arr[n - 1];
    for (int i = 1; i < n; i++) {
        psum[i] = arr[n - i - 1] + psum[i - 1];
    }

    ll min = 1e16L;

    for (int i = 0; i < n - 1; i++) {
        ll tmp = abs(psum[n - 1] - 2 * psum[i]);
        if (tmp < min) {
            min = tmp;
        }
    }

    cout << min << endl;
}
