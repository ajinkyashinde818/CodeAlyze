#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <math.h>
#include <queue>
using namespace std;
typedef long long ll;

int main() {
    int N, R;
    cin >> N;
    cin >> R;
    if (N >= 10) {
        cout << R << endl;
    } else {
        cout << R + (100 * (10 - N)) << endl;
    }
    return 0;
}
