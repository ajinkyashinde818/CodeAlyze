#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
    int N;
    cin >> N;
    long long m = 1000000000;
    long long ans = 0;
    long long a;
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> a;
        if (a < 0) count++;
        a = abs(a);
        m = min(m, abs(a));
        ans += a;
    }
    cout << ((count % 2) ? ans - 2 * abs(m) : ans) << endl;
    return 0;
}
