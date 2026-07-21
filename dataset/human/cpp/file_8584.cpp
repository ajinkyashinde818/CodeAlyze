#include <bits/stdc++.h>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    string ans = "No";
    vector<string> A(N), B(M);
    for (int i = 0; i < N; i++){
        cin >> A.at(i);
    }
    for (int k = 0; k < M; k++){
        cin >> B.at(k);
    }
    int pos;
    if (A == B) ans = "Yes";
    for(int i = 0; i < N ; i++){
        pos = A[i].find(B[0]);
        if (pos != string::npos && i+M < N){
            for (int k = 1; k < M; k++){
                if (A[i+k].substr(pos, M) != B[k]){
                    break;
                }
                if (k == M -1){
                    ans = "Yes";
                    break;
                }
            }
        }
    }
    cout << ans << endl;   
}
