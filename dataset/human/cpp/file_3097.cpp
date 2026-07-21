#include <cstdio>
#include <stack>
#include <set>
#include <cmath>
#include <map>
#include <time.h>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <memory.h>
#include <cstdlib>
#include <queue>
#include <iomanip>
#define P pair<int, int>
#define LL long long
#define LD long double
#define PLL pair<LL, LL>
#define mset(a, b) memset(a, b, sizeof(a))
#define PI acos(-1.0)
#define random(x) rand() % x
using namespace std;
const int inf = 0x3f3f3f3f;
const LL __64inf = 0x3f3f3f3f3f3f3f3f;
const int MAX = 1e5 + 5;
const int Mod = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    vector<LL> a(n);
    bool flag = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        flag ^= a[i] < 0;
        a[i] = abs(a[i]);
    }
    LL sum = 0;
        for(auto x : a) sum += x;
    if(!flag)
    {
        cout << sum << endl;
    }
    else 
        cout << sum -2 * *min_element(a.begin(), a.end()) << endl;
    return 0;
}
