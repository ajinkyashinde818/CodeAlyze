#include <bits/stdc++.h>
using namespace std;

int n, counts=0;
long long int ans, sum = 0;
vector<long long int> a(500000);

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a.at(i);

    long long int mina = 2000000000;
    for (int i = 0; i < n; ++i)
    {
        if (a.at(i) < 0)
        {
            counts ++;
        }

        sum += abs(a.at(i));
        if (mina > abs(a.at(i)))
        {
            mina = abs(a.at(i));
        }
    }

    if (counts%2 == 0)
    {
         ans = sum;
    } else {
        ans = sum - 2*mina;
    }

    cout << ans << endl;
}
