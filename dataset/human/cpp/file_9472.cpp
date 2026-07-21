#include <iostream>
using namespace std;

int M, N;
char A[50][51], B[50][51];

void solve() {
    bool match = false;
    for (int i = 0; i <= N-M; i++) {
        for (int j = 0; j <= N-M; j++) {
            bool f = true;
            for (int k = 0; k < M; k++) {
                for (int l = 0; l < M; l++) {
                    if (A[i+k][j+l] != B[k][l]) {
                        f = false;
                        break;
                    }
                }
                if (!f) break;
            }
            if (f) {
                match = true;
                break;
            }
        }
    }
    if (match) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            cin >> B[i][j];
        } 
    }

    solve();
}
