#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> A(N), B(M);
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    for (int i = 0; i < M; i++) {
        cin >> B.at(i);
    }

    bool ans = false;
    for (int i = 0; i + M <= N; i++) {
        for (int j = 0; j + M <= N; j++) {
            bool keep = true;
            for (int k = 0; k < M; k++) {
                if (A.at(i + k).substr(j, M) != B.at(k)) {
                    keep = false;
                }
            }
            if (keep) {
                ans = true;
            }
        }
    }

    if (ans) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
