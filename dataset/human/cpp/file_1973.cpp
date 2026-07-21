#include<algorithm>
#include<climits>
#include<cmath>
#include<cstdlib>
#include<iomanip>
#include<iostream>
#include<numeric>
#include<string>
using namespace std;

long gcd(long x, long y) { if (x > y) { return gcd(y, x); } long r; while (y != 0) { r = x % y; x = y; y = r; }return x; }
long lcm(long x, long y) { return(x / gcd(x, y)) * y; }
void indexsort(long* first, long* last, long* func) { sort(first, last, [&](long a, long b) {return func[a] < func[b]; }); }
//--------------------

int main() {

	long res;
	long N; cin >> N;
	long A[100009]; for (int i = 0; i < N; i++) cin >> A[i];

	long absum = 0, pmin = INT_MAX, nmax = INT_MIN, countn = 0;

	for (int i = 0; i < N; i++) {
		absum += abs(A[i]);
		if (A[i] >= 0) pmin = min(pmin, A[i]); else { nmax = max(nmax, A[i]); countn++; }
	}

	res = (countn % 2 == 0) ? absum : absum - 2 * min(abs(pmin), abs(nmax));

	cout << res << endl;
}
