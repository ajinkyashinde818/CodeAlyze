#include<bits/stdc++.h>
using namespace std;

int n, m;

int main(void){
    cin >> n >> m;
    vector<string> A(n);
    vector<string> B(m);
    for(int i = 0; i < n; i++) cin >> A[i];
    for(int i = 0; i < m; i++) cin >> B[i];
    bool matched = false;
    for(int i = 0; i <= n-m; i++){
        for(int j = 0; j <= n-m; j++){
            bool tmp = true;
            for(int s = 0; s < m; s++){
                for(int t = 0; t < m; t++){
                    if(A[i+s][j+t] != B[s][t]) tmp = false;
                }
            }
            if(tmp){
                matched = true;
                i = j = n-m+1;
            }
        }
    }
    if(matched) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
