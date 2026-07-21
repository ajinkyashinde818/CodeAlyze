#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>

using namespace std;
using llng = long long;

/* Declarations */
int N, M;
vector<string> A, B;

void solve() {
    bool flg = false;
    for (int i=0; i<=N-M; i++) {
        for (int j=0; j<=N-M; j++) {
            flg = true;
            for (int k=0; k<M; k++) {
                for (int l=0; l<M; l++) {
                    if (A[i+k][j+l] != B[k][l]) {
                        flg = false;
                        break;
                    }
                }
                if (!flg) break;
            }
            if (flg) break;
        }
        if (flg) break;
    }
    cout << (flg ? "Yes" : "No") << endl;
}

int main() {
    cin >> N >> M;
    string tmp;
    for (int i=0; i<N; i++) {
        cin >> tmp;
        A.push_back(tmp);
    }
    for (int i=0; i<M; i++) {
        cin >> tmp;
        B.push_back(tmp);
    }

    solve();

    return 0;
}
