#include <bits/stdc++.h>

using namespace std;

string template_matching (vector<string> &A, vector<string> &B, int N, int M) {

    bool exist;
    for (int i = 0; i <= N - M; i++) {
        for (int j = 0; j <= N - M; j++) {
            exist = true;
            for (int k = 0; k < M; k++) {
                for (int l = 0; l < M; l++) {
                    if (A[i + k][j + l] != B[k][l]) {
                        exist = false;
                    }
                }
            }
            if (exist) {
                return "Yes";
            }
        }
    }

    return "No";
}

int main () {

    int N, M;
    cin >> N >> M;

    vector<string> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<string> B(M);
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }

    cout << template_matching(A, B, N, M) << endl;

    return 0;
}
