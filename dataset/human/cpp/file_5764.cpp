#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
typedef long long ll;
class segtree
{
public:
	int ko[1000000][2];
	int pt;
	ll ans;
	void init()
	{
		ko[0][0] = ko[0][1] = -1;
		pt = 1;
		ans = 0;
	}
	void add(string s)
	{
		int now = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (ko[now][s[i] - '0'] == -1)
			{
				ko[now][s[i] - '0'] = pt;
				ko[pt][0] = ko[pt][1] = -1;
				pt++;
			}
			now = ko[now][s[i] - '0'];
		}
	}
	void dfs(int node, ll len)
	{
		for (int i = 0; i < 2; i++)
		{
			if (ko[node][i] == -1)ans ^= len&-len;
			else dfs(ko[node][i], len - 1);
		}
	}
};
segtree tree;
int main()
{
	tree.init();
	int num;
	ll len;
	scanf("%d%lld", &num, &len);
	for (int i = 0; i < num; i++)
	{
		string s;
		cin >> s;
		tree.add(s);
	}
	tree.dfs(0, len);
	if (tree.ans == 0)printf("Bob\n");
	else printf("Alice\n");
}
