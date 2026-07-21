#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; ++i) cin >> A[i];

    int M = 1001001001;
    bool cnt = false;
    bool zero = false;
    long long res = 0;

    for(int i=0; i<N; ++i) {
        res += abs(A[i]);
        M = min(M, abs(A[i]));
        if(A[i] < 0) cnt = !cnt;
        if(A[i] == 0) zero = true;
    }

    if(!cnt || zero) cout << res << endl;
    else cout << res - 2*M << endl;
}
