#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool check(int h, int w, int N, int M, const vector<string>& A, const vector<string>& B){
    if(h < 0 || h+M-1 >= N || w < 0 || w + M-1 >= N) return false;
    for(int i = h; i < h+M; ++i){
        for(int j = w; j < w+M; ++j){
            if(A[i][j] != B[i-h][j-w]){
                return false;
            }
        }
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N,M;
    cin >> N >> M;
    vector<string> A(N), B(M);
    for(int i = 0; i < N; ++i) cin >> A[i];
    for(int i = 0; i < M; ++i) cin >> B[i];
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            if(check(i, j, N, M, A, B)){
                cout << "Yes" << '\n';
                return 0;
            }
        }
    }
    cout << "No" << '\n';
    return 0;
}
