#include <iostream>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <limits>
#include <algorithm>
#include <functional>

#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, R;
    cin >> N >> R;

    if (N >= 10)
    {
        cout << R;
    }
    else
    {
        cout << (10 - N) * 100 + R;
    }

    return 0;
}
