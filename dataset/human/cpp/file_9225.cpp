#include <bits/stdc++.h>
using namespace std;

int main() {
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());

    int N, M;
    cin >> N >> M;
    string A[N], B[M];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }

    // テンプレート画像の左上の点を動かす
    for (int y0 = 0; y0 < N-M+1; y0++) {
        for (int x0 = 0; x0 < N-M+1; x0++) {
            // チェック
            bool isOK = true;
            for (int y = 0; y < M; y++) {
                for (int x = 0; x < M; x++) {
                    if (B[y][x] != A[y+y0][x+x0]) {
                        isOK = false;
                    }
                }
            }
            if(isOK) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;

    
}
