#include <iostream>
using namespace std;

int main()
{
    int r, g, b, n;
    cin >> r >> g >> b >> n;

    int cnt = 0;
    for (int ri = 0; ri <= n / r; ri++)
    {
        int rest = n - r * ri;
        if (rest == 0)
        {
            cnt++;
            continue;
        }
        else if (rest < 0)
        {
            break;
        }

        for (int gi = 0; gi <= n / g; gi++)
        {
            rest = n - r * ri - g * gi;
            if (rest < 0)
            {
                break;
            }

            if (rest % b == 0)
            {
                cnt++;
            }
        }
    }

    cout << cnt << endl;
    return 0;
}
