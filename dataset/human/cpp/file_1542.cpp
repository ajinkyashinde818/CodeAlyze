#include "bits/stdc++.h"

using namespace std;

//------------------------------- Libraries --------------------------------//

//------------------------------- Type Names -------------------------------//

using i64 = int_fast64_t;

using seika = string;
//akari : 1D, yukari : 2D, maki : 3D vector
template <class kizuna>
using akari = vector<kizuna>;
template <class yuzuki>
using yukari = akari<akari<yuzuki>>;
template <class tsurumaki>
using maki = akari<yukari<tsurumaki>>;
//akane : ascending order, aoi : decending order
template <class kotonoha>
using akane = priority_queue<kotonoha, akari<kotonoha>, greater<kotonoha>>;
template <class kotonoha>
using aoi = priority_queue<kotonoha>;

//------------------------------- Dubug Functions ---------------------------//
inline void print()
{
    cout << endl;
}
template <typename First, typename... Rest>
void print(const First &first, const Rest &... rest)
{
    cout << first << ' ';
    print(rest...);
}
//------------------------------- Solver ------------------------------------//

void solve()
{
    int n, k;
    cin >> n;
    if (n == 1)
    {
        cout << "Yes\n2\n1 1\n1 1\n";
        return;
    }
    for (k = 1; k <= n; k++)
    {
        if (k * (k - 1) == 2 * n)
        {
            break;
        }
    }
    if (k > n)
    {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl
         << k << endl;
    int cur = 1;
    yukari<int> as(k);
    for (int i = 0; i < k - 1; i++)
    {
        for (int j = i + 1; j < k; j++)
        {
            as[i].push_back(cur);
            as[j].push_back(cur);
            cur++;
        }
    }
    for (auto &v : as)
    {
        cout << k - 1 << ' ';
        for (int x : v)
        {
            cout << x << ' ';
        }
        cout << endl;
    }
}

int main()
{
    solve();
    return 0;
}
