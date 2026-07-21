#include <iostream>
#include <cstdio>
using namespace std;

int main(void) {
    int N,M;cin>>N>>M;
    char A[N][N],B[M][M];
    for (int i = 0; i < N; i++) {
        string a;cin>>a;
        for (int j = 0; j < N; j++) A[i][j] = a[j];
    }
    for (int i = 0; i < M; i++) {
        string b;cin>>b;
        for (int j = 0; j < M; j++) B[i][j] = b[j];
    }
/*
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c", A[i][j]);
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            printf("%c", B[i][j]);
        }
        cout << endl;
    }
*/
    // 左上の位置をずらして、ループ
    for (int start_x = 0; start_x <= N - M; start_x++) {
        for (int start_y = 0; start_y <= N - M; start_y++) {
            bool flg = true;
            for (int i = start_x; i < start_x + M; i++) {
                for (int j = start_y; j < start_y + M; j++) {
                    if (A[i][j] != B[i - start_x][j - start_y]) flg = false;
                }
            }
            if (flg) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
