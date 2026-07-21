#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#include <cassert>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

int main() {
    int R, G, B, N;
    cin  >> R >> G >> B >> N;

    int ret = 0;
    for(int i=0; i<=N; ++i) {
        for(int j=0; j<=N; j++) {
            int rem = N - i*R - j*G;
            if(rem < 0)
                continue;
            if(rem % B == 0) {
                ++ret;
            }
        }
    }
    cout << ret << endl;
    return 0;
}
