#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    

    int n, r;
    cin >> n >> r;
    if (n >= 10)
        cout << r;
    else
        cout << (10 - n) * 100 + r;

    return 0;
}
