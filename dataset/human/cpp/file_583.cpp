#include <algorithm>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;


int main() {
    int R, G, B, N;
    cin >> R >> G >> B >> N;

    int res = 0;
    for (int r = 0; r <= N / R; r++) {
        for (int g = 0; g <= (N - r * R) / G; g++) {
            if ((N - r * R - g * G) % B == 0) res++;
        }
    }

    cout << res << endl;

    return 0;
}
