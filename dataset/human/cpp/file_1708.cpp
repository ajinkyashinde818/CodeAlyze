#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cmath>
#include <iomanip>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> V;
typedef map<int, int> M;

constexpr ll INF = 1e18;
constexpr ll MOD = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int cnt = 0;
    int si = 0;
    for (int i = 1; i <= 1000; i++)
    {
        cnt += i;
        si++;
        if (n == cnt)
            break;
    }

    if (n != cnt)
    {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl
         << si + 1 << endl;

    si++;
    cnt = 1;

    V ans[1100];
    for (int i = 0; i < si; i++)
    {
        for (int j = i + 1; j < si; j++)
        {
            ans[i].push_back(cnt);
            ans[j].push_back(cnt);

            cnt++;
        }
    }

    for (int i = 0; i < si; i++)
    {
        cout << ans[i].size();
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << " " << ans[i][j];
        }
        cout << endl;
    }

    return 0;

    int t[1100][1100];

    cnt = 1;
    for (int i = 0; i < si; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            t[i][j] = cnt;
            cnt++;
        }
    }

    for (int i = 0; i < si; i++)
    {

        cout << si;

        for (int j = 0; j < i; j++)
        {
            cout << " " << t[i][j];
        }

        for (int j = i; j < si; j++)
        {
            cout << " " << t[j][i];
        }

        cout << endl;
    }

    cout << si;

    cnt = 2;
    for (int i = 0; i < si; i++)
    {
        cout << " " << cnt * (cnt - 1) / 2;
        cnt++;
    }

    cout << endl;

    return 0;
}
