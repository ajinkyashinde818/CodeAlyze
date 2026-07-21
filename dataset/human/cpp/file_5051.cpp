/*我是萌新*/
#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include <iomanip> 
typedef long long LL;
const int mod = 1000000009;
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    LL n, r;
    while (cin >> n >> r)
    {
        if (n >= 10)
            cout << r << '\n';
        else cout << 100 * (10 - n) + r << '\n';
    }
}
