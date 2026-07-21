#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;

    long A[N];
    for (int n = 0; n < N; n++)
    {
        cin >> A[n];
    }

    long min_abs = 1000000000;
    int minus_num = 0;
    long S = 0;

    for (int n = 0; n < N; n++)
    {
        min_abs = min(min_abs, abs(A[n]));
        S += abs(A[n]);
        if (A[n] < 0)
        {
            minus_num++;
        }
    }

    if (minus_num % 2 == 0)
    {
        cout << S;
    }
    else
    {
        cout << S - min_abs * 2;
    }

    return 0;
}
