#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <stack>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {

    int N, R;
    cin >> N >> R;

    if (N >= 10) {
        cout << R << endl;
    } else {
        cout << (R + 100 * (10 - N)) << endl;
    }
    return 0;
}
