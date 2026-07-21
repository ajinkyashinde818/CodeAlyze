#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void)
{
    int N;
    cin >> N;
    
    ll total = 0;

    vector<int> a(N);

    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        total += (ll) a[i];
    }

    vector<ll> candidates(N-1, 0);
    ll sum = 0;
    for(int i = 0; i < N-1; i++){
        sum+=(ll) a[i];
        candidates[i] = abs(sum - (total - sum));
    }

    ll result = *min_element(candidates.begin(), candidates.end());
    cout << result << endl;

    return 0;
}
