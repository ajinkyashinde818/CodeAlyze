#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<char>> A(N, vector<char>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> A[i][j];
        }
    }

    vector<vector<char>> B(M, vector<char>(M));
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> B[i][j];
        }
    }

    for (int i_shift = 0; i_shift <= N - M; ++i_shift) {
        for (int j_shift = 0; j_shift <= N - M; ++j_shift) {
            bool match = true;
            for (int i = 0; i < M && match; ++i) {
                for (int j = 0; j < M && match; ++j) {
                    if (B[i][j] != A[i + i_shift][j + j_shift]) {
                        match = false;
                    }
                }
            }
            if (match) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
