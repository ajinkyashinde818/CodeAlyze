#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, M;
string A[50], B[50];

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) cin >> B[i];

    bool found = false;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i + M - 1 >= N || j + M - 1 >= N) continue;

            bool tmp = true;
            for (int k = 0; k < M; k++) {
                for (int l = 0; l < M; l++) {
                    if (A[i+k][j+l] != B[k][l]) {
                        tmp = false;
                        break;
                    }
                }
                if (!tmp) break;
            }

            if (tmp) {
                found = true;
                break;
            }
        }

        if (found) break;
    }

    cout << ((found) ? "Yes" : "No") << endl;

    return 0;
}
