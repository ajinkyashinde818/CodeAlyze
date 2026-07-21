#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    for(auto &e : A) cin >> e;
    sort(A.begin(), A.end(), [](int a, int b){
        return abs(a) > abs(b);
    });
    for(int i = 0; i < N - 1; ++i) {
        if(A[i] < 0) {
            A[i] = -A[i];
            A[i + 1] = -A[i + 1];
        }
    }
    cout << accumulate(A.begin(), A.end(), 0LL) << '\n';
    return 0;
}
