#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

void main_()
{
    ll N;
    cin >> N;
    vector<ll> as;
    as.reserve(N);
    copy_n(istream_iterator<ll>(cin), N, back_inserter(as));

    vector<ll> sums;
    sums.reserve(N);
    partial_sum(begin(as), end(as), back_inserter(sums));

    vector<ll> abss;
    abss.reserve(N);
    transform(begin(sums), end(sums) - 1, back_inserter(abss),
        [total = sums.back()](auto x) {
            auto y = total - x;
            return abs(x - y);
        });

    cout << *min_element(begin(abss), end(abss)) << endl;
}
int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    main_();
    return 0;
}
