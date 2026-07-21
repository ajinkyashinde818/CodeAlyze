#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;

    vector<string> A(N);
    vector<string> B(M);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }

    for (int i = 0; i < N - M + 1; i++) {
        for (int j = 0; j < N - M + 1; j++) {
            bool same = true;
            for (int k = 0; k < M; k++) {
                for (int l = 0; l < M; l++) {
                    if (B[k][l] != A[k + i][l + j]) {
                        same = false;
                    }
                }
            }
            if (same) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;

    return 0;
}
