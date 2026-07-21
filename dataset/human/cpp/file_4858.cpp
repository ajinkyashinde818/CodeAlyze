#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int i, j;
    int n, r;
    int ans;

    cin >> n >> r;
    if (n < 10) {
        ans = r + (100 * (10 - n));
    } else {
        ans = r;
    }

    cout << ans << endl;

    return 0;
}
