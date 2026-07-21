#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <deque>
#include <set>
#include <iomanip>
#include <utility>
typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
	int N, R;
	cin >> N >> R;
	if(N>=10) cout << R << endl;
	else cout << R+100*(10-N) << endl;
	return 0;
}
