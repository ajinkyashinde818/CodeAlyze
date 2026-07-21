#include"bits/stdc++.h"
using namespace std;
using ll = int64_t;

int main() {
    ll N;
    string S;
    cin >> N >> S;
    if (S[0] == 'W') {
        cout << 0 << endl;
        return 0;
    }

    constexpr ll MOD = 1e9 + 7;
    ll ans = 1;
    for (ll i = 1; i <= N; i++) {
        (ans *= i) %= MOD;
    }
    ll line_num = 1;
    for (ll i = 1; i < 2 * N; i++) {
        //Bのとき奇数回、Wのとき偶数回反転させなければならない
        //またlineを残りの数以上伸ばすこともできない
        ll rem = 2 * N - i - 1;
        if (line_num >= rem) {
            //強制的にキャッチ
            if (line_num % 2 != (S[i] == 'B')) {
                //色がダメ
                ans = 0;
            } else {
                (ans *= line_num--) %= MOD;
            }
            continue;
        }
        if (line_num % 2 == (S[i] == 'B')) {
            //ここでキャッチ
            (ans *= line_num--) %= MOD;
        } else {
            //ここから伸ばす
            line_num++;
        }
    }

    cout << ans << endl;
}
