#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    long long S = 0LL, s = 0LL;
    long long min = 1000000000000000000LL;

    for(int i = 0; i < N; i++) {
        cin >> A.at(i);
        S += A.at(i);
    }
    for(int i = 0; i < N - 1; i++) {
        s += A.at(i);
        min = (min < llabs(2 * s - S)) ? min : llabs(2 * s - S);
    }
    cout << min << endl;

    return 0;
}
