#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <bitset>
#include <iomanip>
 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(int argc, const char * argv[]) {
    int N, R; cin >> N >> R;
    cout << (N >= 10 ? R : R + 100 * (10 - N)) << endl;
    return 0;
}
