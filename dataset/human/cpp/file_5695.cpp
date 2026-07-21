#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>

using namespace std;

const int MAXN = 100005;

typedef long long s64;

struct Node *nil = 0;
struct Node
{
	int dep;
	Node *c[2];
	
	Node() {}
	Node(int x) : dep(x)
	{
		c[0] = c[1] = nil;	
	}
};

class Trie
{
private:
	s64 L;
	Node *root;
	
public:
	
	Trie(s64 x) : L(x)
	{ 
		root = new Node(0);
	}
	
	void insert(const string &s)
	{
		Node *p = root;
		for (int i = 0; i < s.size(); i++)
		{
			int x = s[i] - '0';
			if (p->c[x] == nil)
				p->c[x] = new Node(p->dep + 1);
			p = p->c[x];
		}
	}
	
	void dfs(Node *p, s64 &v)
	{
		s64 h = L - p->dep;
		if ((p->c[0] == nil) ^ (p->c[1] == nil))
		{
			v ^= (h & -h);
		}
		if (p->c[0] != nil) dfs(p->c[0], v);
		if (p->c[1] != nil) dfs(p->c[1], v);
	}
	
	s64 getans()
	{
		s64 ret = 0;
		dfs(root, ret);
		return ret;
	}
};

string s;

s64 n, L;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> L;
	Trie t(L);
	for (int i = 1; i <= n; i++)
		cin >> s, t.insert(s);
	s64 res = t.getans();
	if (res == 0)
		cout << "Bob" << endl;
	else
		cout << "Alice" << endl;
	return 0;	
}
