#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
    int N, M;
    cin >> N >> M;
    vector<string> A(N), B(M);
    for(int i=0; i<N; i++) {
        cin >> A[i];
    }
    for(int j=0; j<M; j++) {
        cin >> B[j];
    }

    for(int i=0; i+M<=N; i++) {
        for(int j=0; j+M<=N; j++) {
            bool ok = true;
            for(int k=0; k<M; k++) {
                if(A[i+k].substr(j, M) != B[k]) {
                    ok = false;
                }
            }
            if(ok) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    return 0;
}
