#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <vector>
#include <functional>
#include <iomanip>
using namespace std;

int main(void)
{
    int T, D, ta, tb, da, db, i, x, y;
    cin >> T >> D >> ta >> tb >> da >> db;

    x = 1;
    y = 0;
    double min = 1000;

    while (1)
    {
        y = 0;
        if (da * x + db * y > D)
            break;

        while (1)
        {
            if (da * x + db * y > D)
                break;

            if (abs(min) > abs((double)((T - ta) * da * x + (T - tb) * db * y) / (double)(da * x + db * y)))
                min = abs((double)((T - ta) * da * x + (T - tb) * db * y) / (double)(da * x + db * y));
            y++;
        }

        x++;
    }

    if (abs(min) > abs(T - tb))
        min = abs(T - tb);

    cout << fixed << setprecision(15) << min << endl;

    return 0;
}
