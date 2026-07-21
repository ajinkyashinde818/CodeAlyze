#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> A(N), B(M);
    for(int i=0; i<N; ++i) {
        cin >> A[i];
    }
    for(int j=0; j<M; ++j) {
        cin >> B[j];
    }
    for(int i=0; i<=N-M; ++i) {
        for(int j=0; j<=N-M; ++j) {
            bool ok = true;
            for(int k=0; k<M; ++k) {
                for(int l=0; l<M; ++l) {
                    ok &= A[i+k][j+l] == B[k][l];
                }
            }
            if(ok) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}
