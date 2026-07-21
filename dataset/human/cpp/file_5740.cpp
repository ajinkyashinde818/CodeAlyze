#include "bits/stdc++.h"
using namespace std;
int mem[100010];

int dp(int x) {
	if(mem[x] != -1) return mem[x];
	set <int> s;
	for(int i = 1; i <= x; i++) {
		int ans = 0;
		for(int j = 1; j < i; j++) {
			ans ^= dp(x - j);
		}
		s.insert(ans);
	}
	int res = 0;
	while(s.count(res)) {
		++res;
	}
	return mem[x] = res;
}

long long fn(long long x) {
	long long ans = 1;
	while(x % 2 == 0) {
		ans <<= 1;
		x >>= 1;
	}
	return ans;
}

struct node {
	node *a[2];
	bool leaf;
	int height;
	node () {
		for(int i = 0; i < 2; i++) {
			a[i] = NULL;
		}
		leaf = false;
		height = 0;
	}
} *root;

void insert(string s) {
	node* cur = root;
	int dis = 0;
	for(int i = 0; i < s.size(); i++) {
		int c = s[i] - '0';
		if(cur -> a[c] == NULL) {
			cur -> a[c] = new node();
		}
		cur = cur -> a[c];
		cur -> height = ++dis;
	}
	cur -> leaf = true;
}

vector <int> v;

void dfs(node* cur) {
	int cnt = 0;
	for(int i = 0; i < 2; i++) {
		if(cur -> a[i]) {
			++cnt;
			dfs(cur -> a[i]);
		}
	}
	if(cnt == 1) {
		v.push_back(cur -> height);
	}		
}




int main(int argc, char const *argv[])
{
	root = new node();
	int n;
	long long L;
	cin >> n >> L;
	for(int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		insert(s);
	}
	dfs(root);

	long long ans = 0;
	for(auto i : v) {
		ans ^= fn(L - i);
	}
	if(ans) {
		cout << "Alice" << endl;
	} else {
		cout << "Bob" << endl;
	}
	return 0;
}
