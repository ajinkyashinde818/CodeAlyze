#include<bits/stdc++.h>
using namespace std;
using ll=long long;
static const ll mod = 1000000007;
/* ちゃんと考えて実装して問題なくACできた時嬉しいよ！！ */

int main(void){
    int n,m;
    cin >> n >> m;
    vector<string> A_nn;
    vector<string> B_mm;
    for(int i=0; i<n; i++){
        string x;
        cin >> x;
        A_nn.push_back(x);
    }
    for(int i=0; i<m; i++){
        string x;
        cin >> x;
        B_mm.push_back(x);
    }

    int flag; //flag==m*mならok
    int ok=0;
    for(int i=0; i<=(n-m); i++){
        for(int j=0; j<=(n-m); j++){
            flag = 0;
            for(int tmp_i=0; tmp_i<m; tmp_i++){
                for(int tmp_j=0; tmp_j<m; tmp_j++){
                    if(A_nn[i+tmp_i][j+tmp_j] == B_mm[tmp_i][tmp_j]){
                        flag += 1;
                    }
                }
            }
            if(flag == m*m){
                ok = 1;
                break;
            }
        }
    }
    if(ok==1) cout << "Yes";
    else cout << "No";
    return 0;
}
