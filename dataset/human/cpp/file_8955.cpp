#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int N, M;
    cin >> N >> M;
 
    string A[50], B[50];
    for (int i = 0; i < N; i++)
        cin >> A[i];
 
    for (int i = 0; i < M; i++)
        cin >> B[i];
 
    for (int i = 0; i + M <= N; i++) {
        for (int j = 0; j + M <= N; j++) {
            bool flag = true;
            for (int k = 0; k < M; k++) {
                if (A[i + k].substr(j, M) != B[k]) {
                    flag = false;
                }
            }
            if (flag) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
 
    return 0;
}
