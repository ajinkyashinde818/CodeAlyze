#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<long long> As(N);
    for (auto & a : As) cin >> a;
    long long cum = accumulate(As.begin(), As.end(), 0LL);
    long long record = abs(cum - As[0] - As[0]);
    for (int i = 0; i < N - 1; ++i){
        cum -= 2 * As[i];
        record = min(record, abs(cum));
    }
    cout << record << endl;
    return 0;
}
