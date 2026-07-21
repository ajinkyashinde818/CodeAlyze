#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A.at(i);
    }

    int64_t sum = 0;
    int n_neg = 0;
    int mn = INT_MAX;
    for (int i = 0; i < N; i++)
    {
        sum += abs(A.at(i));
        mn = min(mn, abs(A.at(i)));
        if (A.at(i) < 0)
        {
            n_neg++;
        }
    }
    if (n_neg % 2 == 0)
    {
        cout << sum << endl;
    }
    else
    {
        cout << sum - 2 * mn << endl;
    }
}
