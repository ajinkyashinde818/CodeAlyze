#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
pair<long long, int> sushi[MAXN];
long long bestBal[MAXN + 1];

long long solve(int n, long long c, pair<long long, int> s[MAXN])
{
    bestBal[n] = 0;
    long long totalVal = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        totalVal += sushi[i].second;
        bestBal[i] = max(bestBal[i + 1], totalVal - (c - s[i].first));
    }
    long long ans = 0;
    totalVal = 0;
    for (int i = 0; i < n; i++)
    {
        totalVal += sushi[i].second;
        ans = max(ans, totalVal - sushi[i].first + max((long long) 0, bestBal[i + 1] - sushi[i].first));
    }
    return ans;
}

int main()
{
    int n;
    long long c;
    cin >> n >> c;
    for (int i = 0; i < n; i++)
    {
        cin >> sushi[i].first >> sushi[i].second;
    }
    long long ans = solve(n, c, sushi);
    for (int i = 0; i < n; i++)
        sushi[i].first = c - sushi[i].first;
    reverse(sushi, sushi + n);
    ans = max(ans, solve(n, c, sushi));
    cout << ans << endl;
    return 0;
}
