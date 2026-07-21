#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    long long N;
    cin >> N;

    vector<long long> sumVec(N, 0);

    long long a;
    cin >> a;
    sumVec[0] = a;

    long long total = a;

    for (long long i = 1; i < N; i++)
    {
        cin >> a;
        sumVec[i] = a + sumVec[i - 1];
        total += a;
    }

    long long ans = LLONG_MAX;
    for (long long i = 0; i < N - 1; i++)
    {
        ans = min(ans, abs(sumVec[i] - (total - sumVec[i])));
    }

    cout << ans << endl;
    return 0;
}
