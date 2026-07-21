#include<cstdio>
#include<iostream>
#include<string>

typedef long long ll;

class Trie {
	private :
		ll l;
		struct Node {
			Node *child[2];
			int vis;
			
			Node () :
				vis(1) {
					child[0] = NULL;
					child[1] = NULL;
				}
		};
		Node *root;
		
		ll Lowbit(ll x) {
			return x & (-x);
		}
	
	public :
		Trie() :
			root(new Node()) {}
			
		void Init(ll x) {
			l = x;
		}
		
		void Insert(std :: string s) {
			Node *now = root;
			for (int i = 0; s[i]; i++) {
				int x = s[i] - '0';
				if (!now->child[x]) {
					now->child[x] = new Node();
				}
				now = now->child[x];
			}
		}
		
		ll DFS(Node *now, int depth) {
			if (!now && depth) {
				return Lowbit(l - depth + 1);
			}
			return DFS(now->child[0], depth + 1) ^ DFS(now->child[1], depth + 1);
		}
		
		ll DFS() {
			return DFS(root, 0);
		}
};

class Solution {
	private :
		int n;
		ll l;
		std :: string s;
		Trie tree;
		
	public :
		void Get() {
			scanf("%d %lld", &n, &l);
			tree.Init(l);
			for (int i = 1; i <= n; i++) {
				std :: cin >> s;
				tree.Insert(s);
			}
		}
		
		void Solve() {
			if (tree.DFS()) {
				printf("Alice\n");
			} else {
				printf("Bob\n");
			}
		}
};
Solution sol;

int main() {
	sol.Get();
	sol.Solve();
}
