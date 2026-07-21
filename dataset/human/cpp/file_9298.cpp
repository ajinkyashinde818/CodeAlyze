#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N, M; cin >> N >> M;
    vector<string> A(N, ""), B(M, "");
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) cin >> B[i];

    for (int i = 0; i + M <= N; i++) {
        for (int j = 0; j + M <= N; j++) {
            bool T = false;
            for (int k = 0; k < M; k++) {
                string a = A[i + k].substr(j, M);
                if (a == B[k]) T = true;
                else {
                    T = false; break;
                }
            }
            if (T) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
