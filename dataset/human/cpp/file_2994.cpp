#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

/* editorial */

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<long long> A(N);
    int minus_num = 0;
    bool exist_zero = false;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        if (A[i] < 0)
        {
            minus_num++;
        }
        if (A[i] == 0)
        {
            exist_zero = true;
        }
    }

    long long sum = 0LL;
    long long mn = 1e9 + 7;
    for (int i = 0; i < N; i++)
    {
        sum += abs(A[i]);
        mn = min(mn, abs(A[i]));
    }

    if (minus_num % 2 == 0 || exist_zero)
    {
        cout << sum << endl;
    }
    else
    {

        cout << sum - 2 * mn << endl;
    }

    return 0;
}
