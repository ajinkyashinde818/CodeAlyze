#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
    cin >> N;
    vector<int> w(N), b(N);
    for (int i = 0; i < N; i++) {
        cin >> w.at(i) >> b.at(i);
    }

    vector<vector<int>> grundy(210, vector<int>(110));
    // grundy数を前計算
    for (int b = 0; b < 101; b++) {
        for (int a = 0; a < 201; a++) {
            // mex と同様 のことを行う
            set<int> st;
            if (a - 1 >= 0) st.insert(grundy[a - 1][b]);  // (ア)白石を一つ取り除く
            for (int c = 1; c <= a && c <= b; c++) {      // (イ)白石を超えない数だけ黒石を取り除く
                st.insert(grundy[a][b - c]);
            }
            if (b - 1 >= 0) st.insert(grundy[a + 1][b - 1]);  //(ウ)黒石を一つの白石に交換する
            int g = 0;
            while (st.count(g)) {
                g++;
            }
            grundy[a][b] = g;
        }
    }

    int xor_sum = 0;
    for (int i = 0; i < N; i++) {
        xor_sum ^= grundy[w[i]][b[i]];
    }

    if (xor_sum == 0) {  // 後手必勝
        cout << 1 << endl;
    } else {  // 先手必勝
        cout << 0 << endl;
    }
}
