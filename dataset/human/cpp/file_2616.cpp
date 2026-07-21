// Shift-JIS（シフトジス）

#include <bits/stdc++.h>
using namespace std;

int N;
vector<long long> A(100000);

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    long long S = 0;
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (A[i] < 0)
        {
            count++;
        }
        S += abs(A[i]);
    }

    long long minAbsA = 1000000000;
    for (int i = 0; i < N; i++)
    {
        if (minAbsA > abs(A[i]))
        {
            minAbsA = abs(A[i]);
        }
    }

    if (count % 2 == 0)
    {
        cout << S << endl;
    }
    else
    {
        cout << S - 2 * minAbsA << endl;
    }
}
