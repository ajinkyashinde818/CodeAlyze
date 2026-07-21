#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <functional>
#include <random>
#include <limits>
#include <string>
#include <sstream>
#include <iomanip>

#include <cassert>
#include <cmath>
#include <ctime>

#pragma comment(linker, "/STACK:200000000")

using namespace std;

mt19937 mt (736);

void solve (istream &cin = std::cin, ostream &cout = std::cout)
{
    int n;
    long long c;

    cin >> n >> c;

    vector<pair<long long, int>> sushi (n);

    for (auto &it : sushi)
        cin >> it.first >> it.second;

    sort (sushi.begin (), sushi.end ());

    auto rev = sushi;

    for (auto &it : rev)
        it.first = c - it.first;

    reverse (rev.begin (), rev.end ());

    vector<pair<long long, long long>> ps (sushi.size () + 1), rs (rev.size () + 1);

    for (int i = 1; i < ps.size (); i++)
    {
        ps[i] = {sushi[i - 1].first, sushi[i - 1].second + ps[i - 1].second};
        rs[i] = {rev[i - 1].first, rev[i - 1].second + rs[i - 1].second};
    }

    for (auto &it : ps)
        it.second -= it.first;
    for (auto &it : rs)
        it.second -= it.first;

    vector<long long> pm (ps.size ()), rm (rs.size ());

    for (int i = 1; i < pm.size (); i++)
    {
        pm[i] = max (pm[i - 1], ps[i].second);
        rm[i] = max (rm[i - 1], rs[i].second);
    }

    long long ans = 0;

    for (int i = 0; i < ps.size (); i++)
    {
        ans = max (ans, ps[i].second - ps[i].first + rm[n - i]);
        ans = max (ans, rs[i].second - rs[i].first + pm[n - i]);
    }

    cout << ans << endl;
}

int main ()
{
    ios_base::sync_with_stdio (false);
    cin.tie (nullptr);

#ifdef LOCAL
    solve ();

    cout << "clock: " << clock () << endl;
#else
    solve ();
#endif // LOCAL

    return 0;
}
