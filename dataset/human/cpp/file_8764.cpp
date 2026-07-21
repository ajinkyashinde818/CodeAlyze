#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <iomanip>
using namespace std;
typedef long long ll;

int main() {
    int N, M; cin >> N >> M;
    
    vector<string> A(N), B(M);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < M; i++) cin >> B[i];
    for(int i = 0; i <= N - M; i++){
        for(int j = 0; j <= N - M; j++){
            bool flag = true;
            for(int k = 0; k < M; k++){
                if(!flag) break;
                for(int l = 0; l < M; l++){
                    if(A[k+i][l+j] != B[k][l]) {
                        flag = false;
                        break;
                    }
                }
            }
            if(flag){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}
