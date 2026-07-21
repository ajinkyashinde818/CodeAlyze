//
// Created by kuroneko on 2019-07-06.
//

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

typedef long long ll;
using namespace std;

int main() {
    int N; cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    sort(A.begin(), A.end());

    for (int i = 0; i < N - 1; i++) {
        if (A[i] < 0 && A[i+1] < 0) {
            A[i] *= -1;
            A[i+1] *= -1;
        } else if (A[i] < 0) {
            if (abs(A[i]) > A[i+1]) {
                A[i] *= -1;
                A[i+1] *= -1;
            }
        }
    }
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        sum += A[i];
    }
    cout << sum << endl;
    return 0;
}
