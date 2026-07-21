#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define MOD 1000000007
using namespace std;

typedef pair<int, int> P;
typedef pair<long long, long long> LLP;

int main() {
    int R, G, B, N;
    cin >> R >> G >> B >> N;
    long long count = 0;
    for (int i = 0; i * R <= N; i++) {
        for (int j = 0; i * R + j * G <= N; j++) {
            if ((N - i * R - j * G) % B == 0) count++;
        }
    }
    cout << count << endl;
    return 0;
}
