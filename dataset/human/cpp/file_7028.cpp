#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <random>
#include <chrono>
#include <tuple>
#include <random>
#include <cmath>

using namespace std;

typedef long long ll;
typedef long double ld;
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

const ll SIZE = 1e6 * 2 + 10, INF = 1e9 * 1e7 + 10, MOD = 1e9 + 7;

ll dp[SIZE][2][2];

int main()
{
    fastInp;

    
    ll n;
    cin >> n;
    vector<ll> vec1(n), vec2(n);

    map<ll, ll> mp1, mp2;
    for (auto &cur : vec1) cin >> cur;
    for (auto &cur : vec2) cin >> cur;

    for (auto cur : vec1) {
        mp1[cur]++;
    }

    for (auto cur : vec2) {
        mp2[cur]++;
    }

    ll sh = 0;

pair<ll, ll> mn2 = {-INF, INF};
    for (auto cur : mp1) {
        ll am = cur.second, vl = cur.first;
mn2.first = max(mn2.first, am);
        mn2.second = min(mn2.second, am);
        if (am > n - mp2[vl]) {
            cout << "No";
            return 0;
        }
    }

    pair<ll, ll> mn = {-INF, INF};
    for (auto cur : mp2) {
        ll am = cur.second, vl = cur.first;
        mn.first = max(mn.first, am);
        mn.second = min(mn.second, am);
        if (am > n - mp1[vl]) {
            cout << "No";
            return 0;
        }
    }

    cout << "Yes\n";
    bool fl = true;
    for (int i = 0; i < vec2.size(); i++) {
        if (vec2[(i + n / 2) % n] == vec1[i]) fl = false;
    }

    if (fl) {
        for (int i = 0; i < vec2.size(); i++) {
            cout << vec2[(i + n / 2) % n] << " ";
        }
        return 0;
    } else {
        vector<ll> check;
        for (int i = 0; i < n; i++) check.push_back(i);
        std::random_device rd;
        std::mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
        shuffle(check.begin(), check.end(), rng);
        check.insert(check.begin(), mn.first);
        check.insert(check.begin(), mn.second);
        check.insert(check.begin(), mn2.first);
        check.insert(check.begin(), mn2.second);
        for (int k = 0; k < n; k++) {
            bool fl = true;
            for (int i = 0; i < vec2.size(); i++) {
                if (vec2[(i + check[k]) % n] == vec1[i]) fl = false;
            }

            if (fl) {
                for (int i = 0; i < vec2.size(); i++) {
                    cout << vec2[(i + check[k]) % n] << " ";
                }
                return 0;
            }
        }
    }

    return 0;
}
