#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, r;
    cin >> n >> r;
    cout << r + max(0, 100 * (10 - n));

    return 0;
}
