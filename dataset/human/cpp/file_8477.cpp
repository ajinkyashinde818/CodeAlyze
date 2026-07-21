#include "bits/stdc++.h"

using namespace std;

void Main() {
    int N, M;
    cin >> N >> M;
    vector<string> A(N, "");
    vector<string> B(M, "");
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < M; ++i) {
        cin >> B[i];
    }

    for (int i = 0; i < N - M + 1; ++i) {
        for (int j = 0; j < N - M + 1; ++j) {
            bool matched = true;
            for (int k = 0; k < M; ++k) {
                if (A[i + k].substr(j, M) != B[k]) {
                    matched = false;
                    break;
                }
            }
            if (matched) {
                cout << "Yes" << endl;
                return;
            }
        }
    }
    cout << "No" << endl;
    return;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
