#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <functional>
#include <array>
#include <map>
#include <queue>
#include <limits.h>
#include <set>
#include <stack>
#include <random>
#include <complex>
#include <unordered_map>
#define rep(i,s,n) for(int i = (s); (n) > i; i++)
#define REP(i,n) rep(i,0,n)
#define RANGE(x,a,b) ((a) <= (x) && (x) < (b))
#define DUPLE(a,b,c,d) (RANGE(a,c,d) || RANGE(b,c,d) || RANGE(c,a,b) || RANGE(d,a,b))
#define INCLU(a,b,c,d) (RANGE(a,c,d) && (b,c,d))
#define PW(x) ((x)*(x))
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MODU 1000000007LL
#define bitcheck(a,b)   ((a >> b) & 1)
#define bitset(a,b)      ( a |= (1 << b))
#define bitunset(a,b)    (a &= ~(1 << b))
#define MP(a,b) make_pair((a),(b))
#define Manh(a,b) (abs((a).first-(b).first) + abs((a).second - ((b).second))
#define pritnf printf
#define scnaf scanf
#define itn int
#define PI 3.141592653589


#define izryt bool
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T &val) {
	std::fill((T*)array, (T*)(array + N), val);
}
pll Dir[8] = { //移動
	{ 0 ,1 },{ -1 ,0 },{ 1 ,0 },{ 0 ,-1 },
	{ 1 ,1 },{ 1 ,-1 },{ -1 ,1 },{ -1 ,-1 }
};

//[a, b)
#define Getsum(ar, a,b) (ar[b] - ar[a])
#define INF 10000000000000000LL

struct Edge {
	ll from, to;
	ll w;
};

typedef vector<vector<Edge>> Graph;
template<typename T> //Tのデフォルトコンストラクタが単位元となる
class ScapegoatTree_Leaf {

public:
	struct Node {
		int range[2]; // [range[0], range[1])
		T val;
		Node *p = NULL, *l = NULL, *r = NULL;
		bool removed = false, leaf;
		int sz = 1, dc = 0, coin = 0;

		Node(Node* par, int rangel, int ranger, Node* left, Node* right) :leaf(false), val(T()), p(par), l(left), r(right) { range[0] = rangel, range[1] = ranger; }
		Node(Node* par, int t, T _val) :leaf(true), val(_val), p(par) { range[0] = t, range[1] = t + 1; }
		void upd() {
			if (!leaf) {
				sz = 1 + l->sz + r->sz;
				dc = removed + l->dc + r->dc;
				range[0] = l->range[0];
				range[1] = r->range[1];
				val = l->val + r->val;
			}
			else
			{
				dc = removed;
			}
		}
		int size() {
			return sz - dc;
		}
	};
#define MAXPOOLSIZE 3000000

	mt19937 engine;

	Node* root = NULL;

	int poolcou = 0;
	Node *nodepool[MAXPOOLSIZE] = {};

	void updpath(Node* node) {
		Node* cur = node;
		while (cur != NULL) {
			cur->upd();
			cur = cur->p;
		}
	}


	int depth(Node* node) {
		Node* cur = node;
		int c = 0;
		while (cur != root) {
			cur = cur->p;
			c++;
		}
		return c;
	}

	void DeleteNode(Node* node) {
		nodepool[poolcou] = node;
		poolcou++;
	}

	Node* NewNode(Node* par, int rangel, int ranger, Node* left, Node* right) {
		Node* ret;
		if (poolcou) {
			ret = nodepool[poolcou - 1], poolcou--;
			ret->removed = false, ret->sz = 1, ret->dc = 0, ret->val = T(), ret->leaf = false, ret->p = par, ret->range[0] = rangel, ret->range[1] = ranger, ret->l = left, ret->r = right;
		}
		else
			ret = new Node(par, rangel, ranger, left, right);
		return ret;
	}

	Node* NewNode(Node* par, int t, T _val) {
		Node* ret;
		if (poolcou) {
			ret = nodepool[poolcou - 1], poolcou--;
			ret->removed = false, ret->sz = 1, ret->dc = 0, ret->leaf = true, ret->p = par, ret->range[0] = t, ret->range[1] = t + 1, ret->val = _val;
		}
		else
			ret = new Node(par, t, _val);
		return ret;
	}

	void getarray(vector<Node*>& ar, Node* node, bool rem) {
		if (node->leaf) {
			if (node->removed && rem)
				DeleteNode(node);
			else
				ar.push_back(node);
		}
		else {
			getarray(ar, node->l, rem);
			getarray(ar, node->r, rem);
			DeleteNode(node);
		}
	}

	Node* makeBST(vector<vector<Node*>>& ar, Node* p, int l, int r) {
		if (r - l == 1) {
			if (ar[l].size() == 1) {
				ar[l][0]->p = p;
				return ar[l][0];
			}
			else {
				Node *lleaf = ar[l][0], *rleaf = ar[l][1], *inter = NewNode(p, lleaf->range[0], rleaf->range[1], lleaf, rleaf);
				lleaf->p = inter;
				rleaf->p = inter;

				inter->upd();
				return inter;
			}
		}
		int mid = (l + r) / 2;
		Node* cur = NewNode(p, -1, -1, NULL, NULL); // updで範囲決定
		cur->l = makeBST(ar, cur, l, mid);
		cur->r = makeBST(ar, cur, mid, r);
		cur->upd();
		return cur;
	}

	Node* rebuild(Node* node, bool rem = false) {
		vector<Node*> ar;
		vector<vector<Node*>> f;
		Node *nodep = node->p;
		bool which = false;// T->r F->l

		if (node->p) {
			which = node->range[1] == node->p->range[1];
		}

		ar.reserve(node->sz);
		getarray(ar, node, rem);

		if (ar.size() == 0) {
			root = NULL;
			return NULL;
		}

		int fc = 1;
		while (fc * 2 <= ar.size())
			fc *= 2;

		vector<int> db(fc), dbb(fc);
		REP(i, fc) db[i] = i;
		shuffle(ALL(db), engine);
		REP(i, ar.size() - fc) dbb[db[i]] = 1;

		for (int i = 0; ar.size() > i; i++) {
			f.push_back(vector<Node*>());
			f[f.size() - 1].push_back(ar[i]);
			if (dbb[f.size() - 1]) {
				i++;
				f[f.size() - 1].push_back(ar[i]);
			}
		}

		Node* nn = makeBST(f, nodep, 0, f.size());

		if (nodep) {
			if (which)
				nodep->r = nn;
			else
				nodep->l = nn;
		}
		else
			root = nn;

		updpath(nn);
		return nn;
	}

	void remove(Node* node) {
		if (node == NULL) return;
		node->removed = true;
		node->val = T();
		updpath(node);

		if (root->dc * 4 > root->sz) {
			rebuild(root, true);
		}
	}

	void remove(int t) {
		remove(search(t));
	}

	Node* search(int t, bool b = false) {
		if (root == NULL) return NULL;

		Node* cur = root;

		while (!cur->leaf) {
			if (cur->l->range[1] > t) {
				cur = cur->l;
			}
			else if (cur->l->range[1] <= t) {
				cur = cur->r;
			}
		}
		if (cur->range[0] == t) return cur;
		else return b ? cur : NULL;
	}

	Node* insert(int t, T val) {
		if (root == NULL) {
			return root = NewNode(NULL, t, val);
		}

		Node *node = search(t, true), *l, *r, *newleaf;

		if (node->range[0] == t) {
			node->removed = false, node->val = val;
			updpath(node);
			return node;
		}

		if (node->range[0] > t) {
			r = node, newleaf = l = NewNode(NULL, t, val);
		}
		if (node->range[0] < t) {
			newleaf = r = NewNode(NULL, t, val); l = node;
		}

		Node*  inter = NewNode(node->p, l->range[0], r->range[1], l, r);
		if (node->p) {
			if (node->range[1] == node->p->range[1])
				node->p->r = inter;
			else
				node->p->l = inter;
		}
		else root = inter;
		l->p = inter;
		r->p = inter;

		updpath(inter);

		//printf("bef %d:", depth(newleaf));
		if (depth(newleaf) > (log(root->sz) / log(3.0 / 2))) {
			Node* cur = newleaf, *last = NULL;
			while (cur->p != NULL) {
				if (cur->sz * 3 > cur->p->sz * 2)
					last = cur->p;
				cur = cur->p;
			}
			if (last != NULL)
				rebuild(last);
		}

		return newleaf;
	}

	T rangequery(int l, int r, Node* node = NULL) { // [l.r)
		if (root == NULL) return T();
		if (node == NULL) node = root;
		l = max(l, node->range[0]);
		r = min(r, node->range[1]);

		if (l == node->range[0] && r == node->range[1]) return node->val;
		if (l >= r) return T();
		T ret = T();
		ret = ret + rangequery(l, min(r, node->l->range[1]), node->l);
		ret = ret + rangequery(max(l, node->r->range[0]), r, node->r);
		return ret;
	}
};


ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

ll factorial(ll n) {//階乗
	static ll memo[400000] = {};

	if (n > 0) {
		if (memo[n] != 0) return memo[n];
		return memo[n] = n * factorial(n - 1) % MODU;
	}
	else {
		return memo[0] = 1;
	}
}
ll mod_pow(ll x, ll n, ll mod) {
	ll res = 1;
	while (n > 0) {
		if (n & 1) res = res * x %mod;
		x = x * x%mod;
		n >>= 1;
	}
	return res;
}

ll divmod(ll a, ll b, ll m) { // a/b(mod m)
								  // a/b (mod m)
								  // a*b^-1
								  // b^-1 * b = 1
								  // b^(m-1) = 1 
								  // b^(m-2) * b = 1
							 	  // b^-1 = b^(m-2)

								  // a/b = a * b^(m-2)

	return (a * 1LL * mod_pow(b, m - 2, m)) % m;
}

ll ncr(ll n, ll r) {
	if (n < r) return 0;
	return divmod(factorial(n) , (factorial(r) * (factorial(n - r)) % MODU),MODU);
}
signed main(void) {

	int n;

	string s;
	cin >> n >> s;

	int cou[26] = {};

	for (auto itr : s) {
		cou[itr - 'a']++;
	}

	ll dp[27][27] = {};
	dp[0][0] = 1;
	REP(i, 26) {
		REP(j, 26) {
			dp[i + 1][j + 1] += dp[i][j] * cou[i];
			dp[i + 1][j] += dp[i][j];

			dp[i + 1][j + 1] %= MODU;
			dp[i + 1][j] %=  MODU;
		}
	}
	int ans = 0;

	rep(i, 1,27)
		ans += dp[26][i] ,ans %= MODU;

	cout << ans << endl;
	
	return 0;
}
