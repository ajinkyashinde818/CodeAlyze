#include <iostream>
using namespace std;

int main() {
    // input
    int N, M;
    cin >> N >> M;
    char A[N][N];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> A[i][j];
        }
    }
    char B[M][M];
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> B[i][j];
        }
    }

    // solve
    bool flag = false;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            bool match = true;
            for (int k = 0; k < M; ++k) {
                for (int l = 0; l < M; ++l) {
                    if (A[i + k][j + l] != B[k][l]) match = false;
                }
            }
            if (match) flag = true;
        }
    }

    // output
    cout << (flag ? "Yes" : "No") << endl;

    return 0;
}
