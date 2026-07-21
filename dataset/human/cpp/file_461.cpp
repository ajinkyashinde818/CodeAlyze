#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v(3);
    int n, cnt = 0;
    cin >> v[0] >> v[1] >> v[2] >> n;
    sort(v.begin(), v.end());
    for (int i = 0; v[0] * i <= n; i++)
    {
        for (int j = 0; v[0] * i + v[1] * j <= n; j++)
        {
            if ((n - (v[0] * i + v[1] * j)) % v[2] == 0)
                cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
