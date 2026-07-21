#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll N;
    cin >> N;
    ll a[N];
    ll S[N+1];
    S[0] = 0;
    for(ll i = 0; i < N; i++)
    {
        cin >> a[i];
        S[i+1] = S[i] + a[i];
    }

    ll minS = 9223372036854775807;
    ll sum = 0;

    for(ll i = 0; i < N-1; i++)
    {
        sum += a[i];
        if(minS > abs((S[N]-sum)-sum))
        {
            minS = abs((S[N] - sum)-sum);
        }
    }
    cout << minS << endl;
    return 0;
}
