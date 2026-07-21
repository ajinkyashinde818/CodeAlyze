#include <iostream>
using namespace std;

int main()
{
    int N;
    int a[200000] = {0};
    long long sum = 0LL;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        sum += (long long)a[i];
    }

    long long snuke = (long long)a[0];
    long long araiguma = sum - a[0];
    long long ans = abs(snuke - araiguma);
    for (int i = 1; i < N - 1; i++)
    {
        snuke += a[i];
        araiguma -= a[i];
        ans = min(ans, abs(snuke - araiguma));
    }
    cout << ans << endl;

    return 0;
}
