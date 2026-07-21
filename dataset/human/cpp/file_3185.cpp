#include <bits/stdc++.h>
using namespace std;
using Int = long long;
int main() 
{
    int N; cin >> N;
    vector<Int> A(N); for (auto &a : A) cin >> a;
    int count = 0;
    for (int i = 0; i < N; i++) count += (A[i] < 0);
    Int abssum = 0, absmin = 1e9;
    for (int i = 0; i < N; i++) {
        abssum += abs(A[i]);
        absmin = min(absmin, abs(A[i]));
    }
    if (count % 2) {
        cout << abssum - absmin*2 << endl;
    } else {
        cout << abssum << endl;
    }
    return 0;
}
