//
// Created by moono on 2018/10/27.
//

#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;





int main() {
    int N, M;
    cin >> N >> M;

    //
    char A[N][N], B[M][M];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> B[i][j];
        }
    }

    //
    int num = 0;
    for (int i = 0; i < N-M+1; ++i) {
        for (int j = 0; j < N-M+1; ++j) {

            //
            bool is_same = true;
            for (int k = 0; k < M; ++k) {
                for (int l = 0; l < M; ++l) {
//                    cout << B[k+i][l+j];
                    if(A[k+i][l+j] != B[k][l]) {
                        is_same = false;
                        break;
                    }
                }
//                cout << endl;
            }
//            cout << "-- -- --" << endl;

            if(is_same)
                num++;
        }
    }

    if(num > 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;


    return 0;
}
