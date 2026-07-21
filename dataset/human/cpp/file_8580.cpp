#include<iostream>
using namespace std;

char img_A[55][55], img_B[55][55];

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cin >> img_A[i][j];
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) cin >> img_B[i][j];
    }
    if (N < M) {
        cout << "No" << endl;
        return 0;
    }
    for (int i = 0; i <= N - M; i++) {
        for (int j = 0; j <= N - M; j++) {
            bool is_correct = true;
            for (int k = 0; k < M; k++) {
                for (int l = 0; l < M; l++) {
                    if (img_A[i + k][j + l] != img_B[k][l]) is_correct = false;
                }
            }
            if (is_correct) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
