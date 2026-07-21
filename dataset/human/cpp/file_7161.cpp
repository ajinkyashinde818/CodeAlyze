#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <iterator>
#include <algorithm>
#include <functional>
#include <typeinfo>
#include <utility>
#include <tuple>
#include <queue>

using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define reprrev(i, a, b) for (int i = (int)(b) - 1; i >= (int)(a); i--)
#define reprev(i, n) reprrev(i, 0, n)

#define answer(formula) formula ? cout << "Yes" << endl : cout << "No" << endl
#define ANSWER(formula) formula ? cout << "YES" << endl : cout << "NO" << endl

#define PI 3.14159265358979323846
#define INF 1050000000
#define MOD 1000000007
#define EPS (1e-10)

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<pair<int, int>> vp;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvll;
typedef vector<vector<bool>> vvb;
typedef vector<vector<char>> vvc;
typedef vector<vector<string>> vvs;
typedef vector<vector<pair<int, int>>> vvp;

constexpr int dy[4] = { 0, 1, 0, -1 };
constexpr int dx[4] = { 1, 0, -1, 0 };

/*<ここから>***********************************************************/

int main()
{
	int N;
	ll sum = 0;
	cin >> N;
	vll a(N);
	rep(i, N) {
		cin >> a[i];
		sum += a[i];
	}

	vll as(N + 1, 0);
	rep(i, N) as[i + 1] = a[i];
	rep(i, N) as[i + 1] += as[i];

	ll mi = 2e+9 + 1;
	repr(i, 1, N) {
		mi = min(mi, abs(as[i] - sum + as[i]));
	}

	cout << mi << endl;

	return 0;
}
