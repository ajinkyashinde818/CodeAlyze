#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector <string> A(N);
    vector <string> B(M);
    bool isFail = false;
    for (int i=0; i<N; i++) cin >> A.at(i);
    for (int i=0; i<M; i++) cin >> B.at(i);
    for (int i=0; i<=N-M; i++) {
        for (int j=0; j<=N-M; j++) {
            isFail = false;
            for (int k=0; k<M; k++) {
                for (int l=0; l<M; l++) {
                    if (A.at(i+k).at(j+l) != B.at(k).at(l)) {
                        isFail = true;
                        break;
                    }
                    else if (k==M-1 && l==M-1) {
                        cout << "Yes\n";
                        return 0;
                    }
                }
                if (isFail) break;
            }
        }
    }
    cout << "No\n";
}
