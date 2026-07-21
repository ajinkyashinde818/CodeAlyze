#include <iostream>
#include <set>
#include <list>
#include <utility>
#include <queue>
#include <memory>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std; 

int
main(int argc, char const *argv[])
{
    int64_t n;
    cin >> n;
    vector<int64_t> a(n);
    int64_t count_minus = 0;
    int64_t min;
    int64_t sum = 0;
    int64_t res;

    for (int64_t i = 0; i < n; ++i) {
	if (i == 0) min = a[i];

	cin >> a[i];
	if (a[i] < 0) {
	    ++count_minus;
	}

	int64_t b;
	b = a[i];
	if (a[i] < 0) b = -b;

	sum += b;
	if (i == 0) {
	    min = b;
	} else {
	    if (min > b) min = b;
	}
    }

    // cerr << "sum is " << sum << ", min is " << min << endl;;
    if ((count_minus % 2) == 1) {
	res = sum - min * 2;
    } else {
	res = sum;
    }

    cout << res << endl;
    return 0;
}
