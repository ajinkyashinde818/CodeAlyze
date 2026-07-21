#include <iostream>
#include <string>
using namespace std;
int main() {
    int N, M; cin >> N >> M;
    string A[N], B[M];
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < M; i++) cin >> B[i];
    bool found = false;
    for(int i = 0; !found && i < N - M + 1; i++) {
        for(int j = 0; !found && j < N - M + 1; j++) {
            for(int k = 0; k < M; k++) {
                if(A[i+k].substr(j, M) != B[k]) break;
                found = k == M-1;
            }
        }
    }
    if(found) cout << "Yes" << endl;
    else cout << "No" << endl;
}
