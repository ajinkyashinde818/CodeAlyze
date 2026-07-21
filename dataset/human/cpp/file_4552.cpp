#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n, r;

    cin >> n >> r;

    if (n >= 10) cout << r << endl;
    else {
        cout << r + 100 * (10 - n) << endl;
    }
}
