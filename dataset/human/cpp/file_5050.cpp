#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>
#include <string>
#include <cmath>
#include <iomanip>
#include <queue>
#include <list>
#include <set>
#include <stack>
#include <cctype>
#include <cmath>
#include <bitset>

using namespace std;

/* typedef */
typedef long long ll;

/* constant */
const int INF = 1 << 30;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;

/* global variables */

/* function */

/* main */
int main(){
    int N, R;
    cin >> N >> R;

    if (N < 10)
        cout << R + 100 * (10 - N) << '\n';
    else
        cout << R << '\n';

}
