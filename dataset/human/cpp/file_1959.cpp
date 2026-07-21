#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int64_t> vs(n);
    int neg_count = 0;
    for (auto& v : vs)
    {
        cin >> v;
        if (v < 0)
        {
            neg_count++;
        }
        v = abs(v);
    }
    sort(vs.begin(), vs.end());
    if (neg_count % 2 == 1)
    {
        vs[0] *= -1;
    }
    int64_t ans = 0;
    for (auto& v : vs)
    {
        ans += v;
    }
    cout << ans << endl;
}
