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
    int64_t r, g, b, n;
    cin >> r >> g >> b >> n;

    int64_t count = 0;
    for (int ir = 0; ir * r <= n; ir++)
    {
        for (int ig = 0; ir * r + ig * g <= n; ig++)
        {
            const auto ball = ir * r + ig * g;
            if ((n - ball) % b == 0)
            {
                count++;
            }
        }
    }
    cout << count << endl;
}
