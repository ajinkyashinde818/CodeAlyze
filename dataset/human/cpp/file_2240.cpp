#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    long long sum_a = 0;
    long long min_a = abs(a[0]);
    int count_minus = 0;
    for (int i = 0; i < n; i++)
    {
        const long long now_a = abs(a[i]);
        sum_a += now_a;
        min_a = min(now_a, min_a);
        if(a[i]<0)
            count_minus++;
    }

    if(count_minus%2==0)
    {
        cout << sum_a << endl;
        return 0;
    }
    else
    {
        cout << sum_a - min_a*2 << endl;
        return 0;
    }

    return 0;
}
