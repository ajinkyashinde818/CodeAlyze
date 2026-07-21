#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    for (int i=0; i<N; i++) cin >> A[i];

    vector<int> L(A.begin(), A.end()-1);
    sort(L.begin(), L.end());

    long long total = accumulate(L.begin(), L.end(), 0LL);
    long long res = total + A[N-1];
    for (int i = 0; i < L.size(); i++) {
        total -= L[i] * 2;
        if (i % 2 == 0)
            res = max(res, total - A[N-1]);
        else
            res = max(res, total + A[N-1]);
    }
    cout << res << endl;
}
