#include "bits/stdc++.h"

using namespace std;
using int64 = long long int;

constexpr int MaxN = 100000 + 10;
constexpr int64 Inf = 1LL << 60;
int64 A[MaxN];
int64 memo[MaxN][2];
int n;

int64 Solve(int no, int negated)
{
    if (no == n - 1)
    {
        return negated ? -A[no] : A[no];
    }

    if (memo[no][negated] != Inf)
    {
        return memo[no][negated];
    }

    int64 value = negated ? -A[no] : A[no];
    return memo[no][negated] = max(Solve(no + 1, false) + value, Solve(no + 1, true) - value);
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    fill((int64 *) memo, (int64 *) memo + MaxN * 2, Inf);

    cout << Solve(0, false) << endl;
}
