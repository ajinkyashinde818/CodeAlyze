#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

#define fs first
#define sc second

int main() {
    int N, R;
    cin >> N >> R;

    if(N >= 10) {
        cout << R << endl;
    } else {
        cout << R + 100 * (10 - N) << endl;
    }

    return 0;
}
