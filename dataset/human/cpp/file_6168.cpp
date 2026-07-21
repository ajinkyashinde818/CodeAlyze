#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

const int MAX_N = 100010;
int par[MAX_N], uniteRank[MAX_N];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, C;
    cin >> N >> C;
    vector<pll> sushies;
    for (int i = 1; i <= N; i++)
    {
        ll X, V;
        cin >> X >> V;
        sushies.emplace_back(X, V);
    }
    sort(sushies.begin(), sushies.end());
    //右(順回り)にある地点まで移動可能な時の最大
    vector<ll> ruisekiRightMax(N + 1);
    ll ruisekiRValue = 0;
    for (int i = 0; i < N; i++)
    {
        ll distance, value;
        tie(distance, value) = sushies.at(i);
        ruisekiRValue += value;
        ruisekiRightMax.at(i + 1) = max(ruisekiRightMax.at(i), ruisekiRValue - distance);
    }
    //左(逆回り)にある地点まで移動可能な時の最大
    vector<ll> ruisekiLeftMax(N + 1);
    ll ruisekiLValue = 0;
    for (int i = N - 1; i >= 0; i--)
    {
        ll distance, value;
        tie(distance, value) = sushies.at(i);
        ruisekiLValue += value;
        ruisekiLeftMax.at(i) = max(ruisekiLeftMax.at(i + 1), ruisekiLValue - (C - distance));
    }
    //左→右のケース(左の距離2倍)
    //左を固定して右の累積Maxとあわせる
    ll answer = 0;
    answer = max(answer, ruisekiRightMax.at(N));
    ruisekiLValue = 0;
    for (int i = N - 1; i >= 0; i--)
    {
        ll distance, value;
        tie(distance, value) = sushies.at(i);
        ruisekiLValue += value;
        answer = max(answer, ruisekiLValue - (C - distance) * 2 + ruisekiRightMax.at(i));
    }
    //右→左のケース(右の距離2倍)
    //右を固定して左の累積Maxとあわせる
    answer = max(answer, ruisekiLeftMax.at(0));
    ruisekiRValue = 0;
    for (int i = 0; i < N; i++)
    {
        ll distance, value;
        tie(distance, value) = sushies.at(i);
        ruisekiRValue += value;
        answer = max(answer, ruisekiRValue - distance * 2 + ruisekiLeftMax.at(i + 1));
    }
    cout << answer << endl;
    return 0;
}
