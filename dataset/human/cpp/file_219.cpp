#include <iostream>
using namespace std;

int main(void)
{
    int rn, gn, bn, n;
    int n1, n2;
    int count = 0;
    cin >> rn >> gn >> bn >> n;

    for (int r = 0; r <= 3000; r++) {
        n1 = r * rn;
        if (n1 > n) break;
        for (int g = 0; g <= 3000; g++) {
            n2 = n1 + g * gn;
            if (n2 > n) break;
            if ((n2 - n) % bn == 0) count++;
        }
    }

    cout << count << endl;

    return 0;
}
