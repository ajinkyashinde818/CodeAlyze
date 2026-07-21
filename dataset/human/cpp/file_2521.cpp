#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    int cnt = 0;
    bool zero = false;
    for (int i = 0; i < N; i++)
    {
        if (A[i] < 0)
        {
            cnt += 1;
        }
        if (A[i] == 0)
        {
            zero = true;
        }
    }
    for (int i = 0; i < N; i++)
    {
        A[i] = abs(A[i]);
    }
    sort(A.begin(), A.end());
    int minA = A[0];
    long long sumA = accumulate(A.begin(), A.end(), 0LL);
    if (cnt % 2 == 0 || zero)
    {
        cout << sumA << endl;
    }
    else
    {
        cout << sumA - 2 * minA << endl;
    }
}
