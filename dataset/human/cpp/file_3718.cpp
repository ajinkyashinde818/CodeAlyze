#include <bits/stdc++.h>
using namespace std;

//vector…可変長、データの大きさに合わせてサイズを変える
//list…双方向リスト、要素を挿入、削除の多いとき
//forward_list
//array…固定長配列
//set…集合
//multiset
//bitset…2進数、固定長ビット列
//map…連想配列、キーと値を関連付ける
//multimap
//deque
//stack…FILO
//queue…FIFO
//priority_queue
//pair…二つの値を一組
//tuple…複数の値を一組

template<typename T>
void remove(std::vector<T>& vector, unsigned int index) {
    vector.erase(vector.begin() + index);
}

template<class T>
T ma(std::vector<T> &v) {
    T maxi = 0;
    for(auto &i:v) maxi = max(maxi, i);
    return maxi;
}

#define rep(i, n, m) for (int i = n; i <= m; i++)
#define Rep(i, n, m) for (int i = m; i >= 1; i--)

typedef long long ll;
typedef unsigned long long ull;

long long ans = 0;

int main() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    rep(i, 1, n) cin >> a[i];
    int flg = 0;
    rep(i, 1, n) {
        if(a[i] < 0) {
            flg++;
        }
    }

    rep(i, 1, n) {
        if (a[i] > 0) ans += a[i];
        else ans += a[i] * (-1);
    }

    if (flg%2) {
        int minm = abs(0-a[1]);
        rep(i, 2, n) {
            minm = min(minm, abs(0-a[i]));
        }
        ans = ans - minm * 2;
    }
    cout << ans << endl;
}
