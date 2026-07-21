#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    int N;
    cin >> N;
    vector<int64_t> arr;
    int64_t cur;
    int64_t sum = 0;
    for (int64_t i = 0; i < N; i++) {
        cin >> cur;
        arr.push_back(cur);
        sum += cur;
    }

    int64_t snuke = 0;
    int64_t bear = 0;
    int64_t ans = INT64_MAX;
    for (int j = 0; j < N - 1; j++) {
        snuke += arr[j];
        bear = sum - snuke;
        ans = min(ans, abs(snuke - bear));
    }
    cout << ans << endl;
    return 0;
}
