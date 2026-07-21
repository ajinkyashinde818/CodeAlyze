#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    bool ans = false;
    int N, M;
    cin >> N >> M;
    vector<string> A(N), B(M);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) cin >> B[i];
    for (int i = 0; i < N - M + 1; i++) {
        for (int j = 0; j < N - M + 1; j++) {
            int cnt = 0;
            for (int k = j; k < j + M; k++) if (A[k].substr(i, M) == B[k-j]) cnt++;
            if (cnt == M) ans = true;
        }
    }
    cout << (ans ? "Yes" : "No") << endl;
}
