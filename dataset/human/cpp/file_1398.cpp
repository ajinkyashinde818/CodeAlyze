#include<bits/stdc++.h>

using namespace std;

const int MaxN = 1e5 + 15;
const int MOD = 1e9 + 7;
const long long INF = 1e18;

int n;
pair<int, int> a[MaxN];

vector <int> ans[MaxN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    freopen("input.txt", "r", stdin);

    cin >> n;

    if(n == 1)
    {
        cout << "Yes\n";
        cout << "2\n";
        cout << "1 1\n1 1\n";
        return 0;
    }

    for(int k = 2; k * (k - 1) <= 2 * n; ++k)
        if(k * (k - 1) == 2 * n)
        {
            int p = 0;
            for(int l = 1; l < k; ++l)
                for(int r = l + 1; r <= k; ++r)
                {
                    ++p;
                    ans[l].push_back(p);
                    ans[r].push_back(p);
                }

            cout << "Yes\n";
            cout << k << '\n';
            for(int i = 1; i <= k; ++i)
            {
                cout << ans[i].size() << ' ';
                for(int x : ans[i])
                    cout << x << ' ';
                cout << '\n';
            }
            return 0;
        }

    cout << "No\n";
    return 0;
}
