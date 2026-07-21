//Beginner
#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <map>
#include <stdio.h>
#include <string.h>
#include <initializer_list>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <queue>
#include <set>
using namespace std;
const int INF = 1 << 29;
int main ()
{
    int N,R;
    cin >> N >> R;
    if (N < 10) {
        cout << (R + (100 * (10 - N))) << endl;
    }
    else {
        cout << R << endl;
    }
    return 0;
}
