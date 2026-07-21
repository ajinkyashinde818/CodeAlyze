#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cstddef>
#include<queue>
#include<math.h>
#include<iomanip>
using namespace std;

int main()
{
    int n, r;
    cin >> n >> r;
    int ans = r;
    if(n < 10) ans = 100 * (10 - n) + r;
    cout << ans << endl;
    return 0;
}
