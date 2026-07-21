#include <bits/stdc++.h>
using namespace std;

constexpr int NG = -1;
constexpr int OK = 0;

int main(void) {
    int N,M;
    string result = "No\n";
    int chk;

    cin >> N >> M;

    vector<string> sn(N);
    vector<string> sm(M);

    for(int i=0;i<N;i++) {
        cin >> sn[i];
    }
    for(int i=0;i<M;i++) {
        cin >> sm[i];
    }
    
    for(int i=0;i<=(N-M);i++) {
    //縦
        for(int j=0;j<=(N-M);j++) {
        // 横
            // M x Mをチェック
            chk = OK;
            for(int k=0;k<M;k++) {
                if(strncmp(&sn[i+k][j],&sm[k][0], M)) {
                    chk = NG;
                    break;
                }
            }
            if(chk == OK) {
                result = "Yes\n";
                goto output;
            }
        }
        
    }

output:
    cout << result;
    return 0;
}
