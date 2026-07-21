// ----------------------------------------------------------
// --https://kenkoooo.com/atcoder/#/table/soma62jp

// ----------------------------------------------------------
#include <stdio.h>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <numeric>
#include <complex>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <functional>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef long double ld;

#define LL_MOD          (ll)1000000007
#define LL_INF          (ll)1 << 62
#define INT_INF         (int)1 << 30

#define rSort(a)        sort(a.rbegin(),a.rend())
#define Sort(a)         sort(a.begin(),a.end())
#define Reverse(a)      reverse(a.begin(),a.end())
#define Sum(a)          accumulate(a.begin(), a.end(), 0)
#define REP(i, n)       for(ui i = 0;i < n;i++)
#define REPR(i, n)      for(ui i = n;i >= 0;i--)
#define FOR(i, m, n)    for(ui i = m;i < n;i++)
#define pb(i)           push_back(i)
#define mp              make_pair
#define SWAP(x,y)       ((x!=y)&&(x^=y,y^=x,x^=y))


int main(int argc, char* argv[]) {
    
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,R;

    cin >> N >> R;

    cout << (N>=10 ? R : R + 100 * (10 - N)) << endl;
    
    return 0;
    
}
