#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> subA(int M, int st_i, int st_j, vector<vector<char>> A) {
    vector<vector<char>> subA(M, vector<char>(M));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            subA[i][j] = A[st_i + i][st_j + j]; 
        }
    }
    return subA;
}

bool fig_match(vector<vector<char>> A, vector<vector<char>> B) {
    bool matched = true;
    int M = A.size();
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            if (A[i][j] != B[i][j]) {
                matched = false;
            }
        }
    }
    return matched;
}

int main(){
int N, M; cin >> N >> M;
vector<vector<char>> A(N, vector<char>(N));
vector<vector<char>> B(M, vector<char>(M));
for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
            cin >> A[i][j];
    }
}
for (int i = 0; i < M; i++) {
    for (int j = 0; j < M; j++) {
            cin >> B[i][j];
    }
}

bool found = false;
for (int i = 0; i < N - M + 1; i++) {
    for (int j = 0; j < N - M + 1; j++) {
        if (fig_match(subA(M, i, j, A), B)) {
            cout << "Yes" << endl;
            return 0;
        }
    }
}
cout << "No" << endl;

}
