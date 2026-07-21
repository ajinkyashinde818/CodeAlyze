#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M; cin >> N >> M;
    vector<vector<char>> A(N, vector<char>(N));
    vector<vector<char>> B(M, vector<char>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cin >> A.at(i).at(j);
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) cin >> B.at(i).at(j);
    }
    
    if (N == M) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (A.at(i).at(j) != B.at(i).at(j)) {
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
        cout << "Yes" << endl;
        return 0;
    }
    
    for (int i = 0; i < N-M; i++) {
        for (int j = 0; j < N-M; j++) {
            bool flag = true;
            for (int k = 0; k < M; k++) {
                for (int l = 0; l < M; l++) {
                    if (A.at(i+k).at(j+l) != B.at(k).at(l)) {
                        flag = false;
                        break;
                    }
                }
                if (!(flag)) break;
            }
            if (flag) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}
