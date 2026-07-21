#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N, M;
    bool isMatched;
    cin >> N >> M;
    vector<string> A(N), B(N);

    for(int i = 0; i < N; i++)  cin >> A[i];
    for(int i = 0; i < M; i++)  cin >> B[i];

    for(int i = 0; i < N - M + 1; i++) {
        for(int j = 0; j < N - M + 1; j++) {
            isMatched = true;
            for(int k = 0; k < M; k++) {
                for(int l = 0; l < M; l++) {
                    if(A[i+k][j+l] != B[k][l]) {
                        isMatched = false;
                        break;
                    }
                }
            }
            if(isMatched) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    return 0;
}
