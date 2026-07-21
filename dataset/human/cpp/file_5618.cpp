#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <bitset>
#include <queue>
#include <stack>
#include <deque>
#include <complex>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <random>
#include <functional>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define int long long
const int N = 500000;
const long long MOD = 1e9 + 7;

int n, k;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    if (n >= 10)
    {
        cout << k;
    }
    else
    {
        cout << k + (10 - n) * 100;
    }
}
