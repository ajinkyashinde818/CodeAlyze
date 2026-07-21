#include <bits/stdc++.h>
using namespace std;

int main(){

    int N;
    cin >> N;
    vector<long long> a(N);
    for(int i = 0; i < N; i++) cin >> a[i];

    for(int i = 1; i < N; i++) a[i] += a[i - 1];

    long long  ans = (1LL << 60LL);
    for(int i = 0; i < N - 1; i++){
        if(ans > abs(2 * a[i] - a.back())) ans = abs(2 * a[i] - a.back());
    }

    cout << ans << endl;

    return 0;
}
