#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T> using V = vector<T>;

template <class T>
ostream& operator <<(ostream& os, vector<T> v) {
    os << "[";
    for (int i = 0; i < v.size() - 1; i++) {
        os << v.at(i) << ", ";
    }
    return os << v.at(v.size() - 1) << "]";
}

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    V<ll> A_list;
    int num_negatives = 0;
    ll min_abs_item = (1 << 29);

    for (int i = 0; i < N; i++) {
        ll tmp;
        cin >> tmp;
        if (tmp < 0) num_negatives += 1;
        min_abs_item = min(min_abs_item, abs(tmp));
        A_list.emplace_back(tmp);
    }

    ll max_sum = 0;
    for (ll A : A_list) max_sum += abs(A);
    if (num_negatives % 2 == 1) {
        max_sum -= min_abs_item * 2;
    }
    cout << max_sum << "\n";
}
