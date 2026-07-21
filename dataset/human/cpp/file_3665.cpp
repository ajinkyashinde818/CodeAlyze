#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    int count_neg = 0;
    long long total = 0ll;

    int a;
    int min_a = numeric_limits<int>::max();

    for(int i=0;i<N;i++) {
        cin >> a;
        if(a < 0) count_neg++;
        total += abs(a);
        min_a = min(min_a, abs(a));
    }

    cout << total - (count_neg%2 == 1 ? 2*min_a : 0) << endl;

    return 0;
}
