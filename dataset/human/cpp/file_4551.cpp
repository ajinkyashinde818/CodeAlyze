#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int r;
    cin >> r;
    if (n >= 10)
    {
        cout << r << endl;
    }
    else
    {
        cout << (r + 100 * (10 - n)) << endl;
    }
}
