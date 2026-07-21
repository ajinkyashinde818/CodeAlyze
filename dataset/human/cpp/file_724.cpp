#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>
#include <set>
#include <map>
#include <cassert>
#include <fstream>

using namespace std;

int main() {
    

    
    int r, g, b, n;
    cin >> r >> g >> b >> n;
    long long ret = 0;
    
    for (int i = 0; i <= (n / r); ++i)
    {
        for (int j = 0; j <= ((n - i * r) / g); ++j)
        {
            if (((n - i * r - j * g) % b) == 0)
            {
                ret++;
            }
        }
    }
    
    cout << ret << endl;
    
    return 0;
}
