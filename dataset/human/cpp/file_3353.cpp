#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> A(N);
    long long ans = 0;
    int minimum = INT_MAX;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        if (A[i] > 0)
        {
            ans += A[i];
            minimum = min(minimum, A[i]);
        }
        else
        {
            ans -= A[i];
            minimum = min(minimum, -A[i]);
        }
    }

    for (int i = 0; i < N - 1; i++)
    {
        if (A[i] < 0)
        {
            A[i + 1] *= -1;
        }
    }
    if (A.back() < 0)
    {
        ans -= 2 * minimum;
    }
    cout << ans << endl;
}
