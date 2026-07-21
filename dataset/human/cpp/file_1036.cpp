#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <cassert>

using namespace std;
using ll = long long;

int main()
{
    int R, G, B, n;
    cin >> R >> G >> B >> n;
    int ans = 0;
        for(int g = 0; g < n/G + 1; g++){
            for(int b = 0; b < n/B + 1; b++){
                if((n-b*B-g*G)%R == 0 && n-b*B-g*G>=0) ans++;
            }
        }   
    cout << ans << endl;
    return 0;
}
