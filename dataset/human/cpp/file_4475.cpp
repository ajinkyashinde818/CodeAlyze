#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <limits>
#include <climits>
#include <cfloat>
#include <functional>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> ans(n, m);
    for(int i=0; i<(n+2)/2; ++i)
        ans[i] = 0;

    cout << ans[0];
    for(int i=1; i<n; ++i)
        cout << ' ' << ans[i];
    cout << endl;

    return 0;
}
