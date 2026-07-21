/**
 *      ABC 54 B
 *      author  : kyomukyomupurin
 *      created : 2018-09-06 04:22:29
**/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, M; cin >> N >> M;
    string A[N + 10] = {}; string B[M + 10] = {};
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < M; ++i) {
        cin >> B[i];
    }

    bool check1 = false;

    for (int i = 0; i < N - M + 1 ; ++i) {
        for (int j = 0; j < N - M + 1; ++j){
            bool check2 = true;
            for (int k = 0; k < M; ++k) {
                for (int l = 0; l < M; ++l) {
                    if (A[i + k][j + l] != B[k][l]){
                        check2 = false;
                    }                    
                }                
            }
            if (check2) check1 = true;
        }
    }
    check1 ? cout << "Yes" : cout << "No";

    return 0;

}
