#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> A(N);
    vector<string> B(M);
    for(int i = 0; i < N; i++){
        cin >> A.at(i); 
    }
    for(int i = 0; i < M; i++){
        cin >> B.at(i);
    }
    bool ans = false; 
    for(int i = 0; i < N-M+1; i++){
        for (int j = 0; j < N-M+1; j++){
            for (int k = 0; k < M; k++){
                bool flag = true;
                for (int l = 0; l < M; l++){
                    if (A.at(i+k)[j+l] != B.at(k)[l]){
                        flag = false;
                        break;
                    }
                    if (k == M-1 && l == M-1) {
                        ans = true;
                    }
                }  
                if (flag == false) break;
            }
        }
    }
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0; 
}
