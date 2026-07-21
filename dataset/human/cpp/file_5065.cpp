#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <functional>
#include <iomanip>
#include <cstring>

using namespace std;

int main() {
    int n, r;
    cin >> n >> r;
    if (n >= 10)
        cout << r;
    else
        cout << 100*(10-n)+r;
}
