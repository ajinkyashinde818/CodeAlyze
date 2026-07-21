#include <bits/stdc++.h>
using namespace std;
int64_t zet(int64_t x, int64_t y){
    if (x >= y) return x - y;
    else return y - x;
}
int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    int64_t y = 0;
    for (int i = 0; i < N; i++){
        cin >> a.at(i);
        y += a.at(i);
    }
    int64_t x = 0, ans_f = 0;
    int64_t ans;
    for (int i = 0; i < N - 1; i++){
        x += a.at(i);
        y -= a.at(i);
        ans = zet(x, y);
        if (i == 0) ans_f = ans;
        else if (ans < ans_f) ans_f = ans;
    }
    cout << ans_f << endl;
}
