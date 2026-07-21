#include<bits/stdc++.h>
using namespace std;
bool equal_image(string a[], string b[], int m) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] != b[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int N, M, right_line = 0;
    cin >> N >> M;
    string A[N];
    string B[M];
    string target[M];
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for(int i = 0; i < M; i++) {
        cin >> B[i];
    }
    for(int i = 0; i < N-M+1; i++) {
        for(int j = 0; j < N-M+1; j++) {
            for(int k = 0; k < M; k++) {
                target[k] = A[i+k].substr(j, M);
            }
            bool equal = equal_image(target, B, M);
            if(equal) {
                cout << "Yes" << endl;
                return 0;
            }
            
        }     
    }
    cout << "No" << endl;
    return 0;
}
