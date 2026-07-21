#include <bits/stdc++.h>
using namespace std;

int main()
{
    //input

    long N;
    bool even = 0;
    vector<int> A(N);
    long sum = 0;
    long min = 1000000000;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        if (abs(A[i]) < min)
        {
            min = abs(A[i]);
        }
        if (A[i] < 0)
        {
            even = 1 - even;
        }
    }

    //ope
    if (even == 0)
    {
        for (int i = 0; i < N; i++)
        {
            sum += abs(A[i]);
        }
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            sum += abs(A[i]);
        }
        sum -= min * 2;
    }
    cout << sum << endl;

    return 0;
}
