#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

char A[51][51];
char B[51][51];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    for(int i = 0; i < N; ++i){   
        for(int j = 0; j < N; ++j){
            cin >> A[i][j];
        }
    }
    for(int i = 0; i < M; ++i){   
        for(int j = 0; j < M; ++j){
            cin >> B[i][j];
        }
    }

    bool ans = false;
    for(int i = 0; i < N - M + 1; ++i){   
        for(int j = 0; j < N - M + 1; ++j){
            bool check = true;
            for(int k = 0; k < M; ++k){
                for(int l = 0; l < M; ++l){
                    if(B[k][l] != A[i + k][j + l]){
                        check = false;
                        break;
                    }
                }
                if(!check) break;
            }
            if(check) ans = true;
        }
    }
    cout << (ans ? "Yes" : "No") << endl;

    return 0;
};
