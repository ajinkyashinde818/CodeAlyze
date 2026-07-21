#include <bits/stdc++.h>
using namespace std;

int main(void)
{

    int n;
    cin >> n;
    vector<int> a(n);
    //全体
    long long sum = 0, x = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a.at(i);
        sum += a.at(i);
    }
    //最小値を求めるので、大きな値を設定
    long long ans = 10000000000000000;

    for (int i = 0; i < n; i++)
    {
        x += a.at(i);
        //片方は1枚以上なのでn-1まで探索
        if (i < n - 1)
        {
            ans = min(ans, abs(sum - x * 2));
        }
    }
    cout << ans << endl;
    return 0;
}
