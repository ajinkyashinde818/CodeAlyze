#include <iostream>
#include <iomanip>
#include <random>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <sstream>
#include <bitset>
#include <cassert>
#include <fstream>
#include <queue>

#define len(X) ((int)(X).size())

#ifdef __LOCAL
	#define DEBUG_OUTPUT_ENABLED 1
	#define DBG(X) dout << #X << "=" << (X) << '\n';
	#define SAY(X) dout << (X) << '\n';
	#define dout   __debug::instance
#else
	#define DEBUG_OUTPUT_ENABLED 0
	#define DBG(X) 42;
	#define SAY(X) 42;
	#define dout CannotCompileBecauseOfDebugOutput
#endif

using namespace std;
using ll = long long int;
using ull = unsigned long long int;
using ld  = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const set<T>& v) { for(auto el: v) cout << el << " "; return os; }
template<typename T, typename S> inline ostream& operator<<(ostream& os, const map<T, S>& v) { for(auto el: v) cout << el << " "; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const multiset<T>& v) { for(auto el: v) cout << el << " "; return os; }
namespace __debug {
	struct DebugStream {
		private:
			bool is_first;
		public:
			DebugStream(bool _is_first): is_first(_is_first) {}
			template<typename T> DebugStream operator<<(const T& value) const {
				assert(DEBUG_OUTPUT_ENABLED);
				if(is_first) cout << "[DBG] ";
				cout << value;
				return DebugStream(false);
			};

			template<typename T> DebugStream printArray(T* l, T* r) {
				assert(DEBUG_OUTPUT_ENABLED);
				if(is_first) cout << "[DBG] ";
				while(l != r) {
					cout << (*l);
					++l;
					if(l == r) {
						cout << '\n';
					} else {
						cout << ' ';
					}
				}
				return DebugStream(false);
			}
	};
	DebugStream instance(true);
};

const int INT_INF = (int)(2e9);
const ll  LL_INF  = (ll)(2e18);

const int NIL = -1;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T> inline T fetch() { T ret; cin >> ret; return ret; }
template<typename T> inline vector<T> fetch_vec(int sz) { vector<T> ret(sz); for(auto& elem: ret) cin >> elem; return ret; }
struct Node {
	int go[2];
	Node() {
		go[0] = go[1] = NIL;
	}
};
vector<Node> T;
int CreateNode() {
	T.emplace_back();
	return len(T) - 1;
}
int n;
ll L, X;
ll Gr(ll lvl) {
	if(lvl == 0) return 0;
	if(lvl & 1) return 1;
	return Gr(lvl >> 1) + 1;
}
void dfs(int v, int depth) {
	int left = T[v].go[0], right = T[v].go[1];
	if(left == NIL && right == NIL) return;
	if(left != NIL) dfs(left, depth + 1);
	if(right != NIL) dfs(right, depth + 1);
	if(left == NIL || right == NIL) {
		X ^= Gr(L - depth);
	}
}
void solve() {
	cin >> n >> L;
	X = 0;
	int root = CreateNode();
	for(int i = 0; i < n; ++i) {
		auto S = fetch<string>();
		int v = root;
		for(auto& ch: S) {
			int c = ch - '0';
			if(T[v].go[c] == NIL) {
				int nv = CreateNode();
				T[v].go[c] = nv;
			}
			v = T[v].go[c];
		}
	}
	dfs(root, 0);
	cout << (X ? "Alice\n" : "Bob\n");
}

int main() {
	fast_io();
	solve();

	return 0;
}
