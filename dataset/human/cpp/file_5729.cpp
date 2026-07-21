#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <queue>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>
#include <complex>
#include <cstdint>
#include <tuple>
#include <numeric>
#define M_PI       3.14159265358979323846


using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v; }
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str(); }

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define FILL(a, x) memset(a, x, sizeof(a))

//repetition
//------------------------------------------
#define FOR(i,s,n) for(int i=s;i<(int)n;++i)
#define REP(i,n) FOR(i,0,n)

class TrieNode {
public:
	TrieNode *ch[2] = { NULL, };
};

class Trie {
public:
	TrieNode *head;
	Trie() {
		head = new TrieNode();
	}
	void add(char *s) {
		int n = strlen(s);
		TrieNode *cur = head;
		for (int i = 0; i < n; i++) {
			if (cur->ch[s[i] - '0'] == NULL)cur->ch[s[i] - '0'] = new TrieNode;
			cur = cur->ch[s[i] - '0'];
		}
	}
};

char str[100005];
LL f(LL x) {
	LL ret = 1;
	while (!(x & 1)) {
		ret <<= 1;
		x >>= 1;
	}
	return ret;
}

LL dfs(TrieNode *u, LL l, LL depth = 0) {
	if (u == NULL)return 0;
	LL ret = 0;
	int cnt = 0;
	if (u->ch[0] != 0)cnt++;
	if (u->ch[1] != 0)cnt++;
	ret ^= dfs(u->ch[0], l, depth + 1);
	ret ^= dfs(u->ch[1], l , depth +1);
	if (cnt == 1) {
		ret ^= f(l - depth);
	}
	return ret;
}

LL g = 0;

int main() {
	int n;
	LL l;
	scanf("%d%lld", &n, &l);
	Trie trie;
	REP(i, n) {
		scanf("%s", str);
		trie.add(str);
	}
	LL ret = dfs(trie.head, l);
	if (ret == 0)printf("Bob\n");
	else printf("Alice\n");
	return 0;
}
