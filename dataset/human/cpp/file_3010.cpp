#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
const ll inf = (1 << 30) - 1;
const ll infll = (1LL << 61) - 1;

ll N, neg, m = infll, sum, zero;

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        ll a;
        cin >> a;
        if (a == 0)
        {
            zero++;
            continue;
        }
        if (a < 0)
            neg++;
        m = min(abs(a), m);
        sum += abs(a);
    }
    if (zero > 0 || neg % 2 == 0)
        cout << sum << endl;
    else
        cout << sum - m * 2 << endl;
}
