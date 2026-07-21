#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
#include <map>
#include <array>
#include <cmath>

long long PRIME = 1e9 + 7;
using namespace std;


int main(){ 
    long long N, M;
    cin >> N >> M;

    vector<int> A(N*N, 0);
    vector<int> B(M*M, 0);

    string buf;

    for(int i = 0; i < N; ++i){
        cin >> buf;
        for(int j = 0; j < N; ++j){
            if(buf[j] == '#'){
                A[N * i + j] = 1;
            }
        }
    }


    for(int i = 0; i < M; ++i){
        cin >> buf;
        for(int j = 0; j < M; ++j){
            if(buf[j] == '#'){
                B[M * i + j] = 1;
            }
        }
    }


    for(int i = 0; i <= N-M; ++i){
        for(int j = 0; j <= N-M; ++j){
            bool check = true;
            for(int k = 0; k < M; ++k){
                for(int l = 0; l < M; ++l){
                    if(A[(i+k)*N+j+l] != B[k*M+l]){
                        check = false;
                        break;
                    }
                }
                if(!check){
                    break;
                }
            }
            if(check){
                cout << "Yes";
                return 0;
            }
        }
    }

    cout << "No";
}
