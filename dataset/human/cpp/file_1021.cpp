#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <queue>
#include <numeric>

using namespace std;

int main() {

    int R, G, B, N, count = 0;

    cin >> R >> G >> B >> N;

    for (int i = 0; R * i <= N; i++) {
        for (int j = 0; G * j <= N; j++) {
            if ((N - R * i - G * j) % B == 0 && N - R * i - G * j >= 0) {
                count++;
            }
        }
    }

    cout << count;

    return 0;
}
