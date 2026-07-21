#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;


int main() {
    int N; cin >> N;
    int count = 0;
    long long mina = 1LL << 60;
    long long a[N]; 

    for (int i = 0 ; i < N; ++i) {
        long long x; cin >> x;
        a[i] = x;
        if (x < 0) ++count;
        mina = min(mina, abs(x));
    }

    long long sum = 0;
    for (int i = 0 ; i < N; ++i) sum += abs(a[i]);
    if (count % 2) sum -= 2 * abs(mina);
    cout << sum << endl;
}
