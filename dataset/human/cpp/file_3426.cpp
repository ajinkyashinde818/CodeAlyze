#include "bits/stdc++.h"
using namespace std;

int main() {
    long long cnt = 0;
    bool flag = false;
    long long MIN = pow(10, 9);
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (A[i] < 0) {
            cnt++;
            MIN = min(MIN, abs(A[i]));
        }
        else if (A[i] > 0) {
            MIN = min(MIN, A[i]);
        }
        else if (A[i] == 0) flag = true;
    }

    long long sum = 0;
    for (int i = 0; i < N; i++) sum += abs(A[i]);
    if (cnt % 2 == 0) cout << sum << endl;
    else {
        if (flag) cout << sum << endl;
        else cout << sum - 2 * MIN << endl;
        
    }
}
