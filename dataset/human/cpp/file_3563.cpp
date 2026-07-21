#include<iostream>
#include<iomanip>
#include<cstdio>

#include<vector>
#include<queue>
#include<set>
#include<map>
#include<string>

#include<algorithm>
#include<cmath>

using namespace std;
typedef long long ll;
template <class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return 1;} return 0;}
template <class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return 1;} return 0;}
const ll INF = 1e9+1;

//Ai+Ai+1が負なら作用時結果が好転する
//全部に実施すると一番端だけ反転する
//偶数の場合まんべんなく実施すると全て反転する

//マイナスの数を端点として、中身が正の数の区間を一連の操作ですべてせいにすることができる
//したがって、マイナスのものは偶数個までなら全て反転することができる
//奇数個の時、絶対値最小のものだけ諦める

int main() {
    
    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    ll cnt = 0;
    ll zerocnt = 0;
    ll minabs = INF;
    ll res = 0;
    for (int i = 0; i < N; i++) {
        chmin(minabs,abs(A[i]));
        res += abs(A[i]);
        if (A[i] < 0) {
            cnt++;
        }
        if (A[i] == 0) zerocnt++;
    }

    if (cnt % 2 == 1) {
        res -= 2 * minabs;
    }
    cout << res << endl;
    

}
