#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long long> a(N);
    long long sum_a = 0;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        sum_a += a[i];
    }

    long long min_diff = 1LL << 62;
    long long sum_sunuke = 0;
    long long sum_raccoon = sum_a;
    for (int i = 0; i + 1 < N; i++) {
        sum_sunuke += a[i];
        sum_raccoon -= a[i];
        min_diff = min(abs(sum_sunuke - sum_raccoon), min_diff);
    }

    cout << min_diff << endl;
    return 0;
}
