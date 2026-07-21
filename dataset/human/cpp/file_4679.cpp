#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void)
{
    int n, r;
    cin >> n >> r;
    int ans;
    if (n >= 10)
    {
        ans = r;
    }
    else
    {
        ans = r + (100 * (10 - n));
    }
    cout << ans << endl;
    return 0;
}
