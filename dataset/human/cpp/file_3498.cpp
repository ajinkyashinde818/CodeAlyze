#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    vector<ll> A(N);
    int minus = 0;
    for (int i = 0; i < N; i++) {
        ll tmp;
        cin >> tmp;
        if (tmp < 0) {
            minus++;
            A[i] = llabs(tmp);
        } else {
            A[i] = tmp;
        }
    }

    sort(A.begin(), A.end());

    if (minus % 2 == 0) {
        cout << accumulate(A.begin(), A.end(), 0LL) << endl;
    } else {
        cout << accumulate(A.begin(), A.end(), 0LL) - A[0] * 2 << endl;
    }

    return 0;
}
