#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll mod = 1e9 + 9;
int n;
ll anser = 0;
ll c;
ll pre[100005];
ll pre2[100005];
ll dis[100005];
ll dis2[100005];
ll v[100005];
ll shun[100005];
ll ni[100005];
int main()
{
        cin >> n >> c;
        for (int i = 1; i <= n; i++)
        {
                cin >> dis[i] >> v[i];
                pre[i] = pre[i - 1] + v[i];
        }
        for (int i = n; i >= 1; i--)
        {
                dis2[n - i + 1] = c - dis[i];
                pre2[n - i + 1] = pre2[n - i] + v[i];
        }
        for (int i = 1; i <= n; i++)
        {
                shun[i] = max(shun[i - 1], pre[i] - dis[i]);
                anser = max(anser, shun[i]);
        }
        for (int i = 1; i <= n; i++)
        {
                ni[i] = max(ni[i - 1], pre2[i] - dis2[i]);
                anser = max(anser, ni[i]);
        }
        //cout << anser << endl;
        for (int i = 1; i <= n; i++)
        {
                anser = max(anser, pre[i] - 2 * dis[i] + ni[n - i]);
                anser = max(anser, pre2[i] - 2 * dis2[i] + shun[n - i]);
        }
        cout << anser << endl;
        return 0;
}
