#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<long long> As(N, 0);
    for (auto & a : As) cin >> a;
    int count_negative = 0;
    long long min_abs = 1e9;
    long long cum_sum = 0;
    for (const auto & a : As){
        if (a < 0) ++count_negative;
        if (abs(a) < min_abs) min_abs = abs(a);
        cum_sum += abs(a);
    }
    if (min_abs == 0 or (count_negative % 2 == 0)){
        cout << cum_sum << endl;
    }else{
        cout << cum_sum - min_abs - min_abs << endl;
    }
    return 0;
}
