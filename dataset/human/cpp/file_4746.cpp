#include <iostream>
#include <queue>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
constexpr ll mod = 1000000007;

int main() {
    int n, r;
    cin >> n >> r;
    cout << (n >= 10 ? r : r + (100 * (10-n))) << endl;
}
