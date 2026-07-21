#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
/* attention
    long longのシフト演算には気をつけよう
    タイポした時のデバッグが死ぬほどきつくなるので変数名は最低3字くらい使った方がいいかも
    sizeは(int)とキャストしよう
    ごちゃごちゃ場合分けを考える前に全探索は考えましたか？
*/

int main(){
    int N, M; cin >> N >> M;
    vector<string> a(N), b(M);
    for(int i=0; i<N; ++i) cin >> a[i];
    for(int i=0; i<M; ++i) cin >> b[i];

    bool flg = false;
    for(int i=0; i<N+1-M; ++i){
        for(int j=0; j<N+1-M; ++j){
            bool ok = true;
            for(int k=0; k<M; ++k){
                for(int l=0; l<M; ++l){
                    if(a[i+k][j+l] != b[k][l]) ok = false;
                }
            }
            if(ok) flg = true;
        }
    }

    if(flg) cout << "Yes" << endl;
    else cout << "No" << endl;
}
