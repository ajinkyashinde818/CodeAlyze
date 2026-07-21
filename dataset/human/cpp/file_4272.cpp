#include<iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
#include <map>
#include <stack>
#include<bitset>
#include<list>
#include<cassert>
#include<numeric>

using namespace std; 


const int N = 1e5 + 5; 
int n;
int s[N];
int t[N];
int ans; 
int s2[N];
int t2[N]; 
map<int, int> cnt1;
map<int, int> cnt2;
map<int, int> par; 
int solve1(int x)
{
	if (par[x] == x)
	{
		return x; 
	}
	return par[x] = solve1(par[x]); 
}

void solve2(int x,int y)
{
	x = solve1(x);
	y = solve1(y); 
	if (x != y)
	{
		par[y] = x; 
	}
}

int main()
{
	cin >> n; 
	for (int i = 1; i <= n; i++) 
	{
		cin >> s[i]; 
	}
	for (int i = 1; i <= n; i++) 
	{
		cin >> t[i]; 
	}
	for (int i = 1; i <= n; i++)
	{
		s[n + 1] ^= s[i]; 
		t[n + 1] ^= t[i]; 
	}
	for (int i = 1; i <= n + 1; i++)
	{
		par[s[i]] = -1; 
		par[t[i]] = -1; 
	}
	for (int i = 1; i <= n + 1; i++)
	{ 
		cnt1[s[i]]++;
	}
	for (int i = 1; i <= n + 1; i++) 
	{
		cnt2[t[i]]++;
	}
	for (int i = 1; i <= n; i++) 
	{
		if (cnt2[t[i]]!=cnt1[t[i]])
		{
			cout << -1; 
			return 0; 
		}
	}
	bool check = true; 
	for (int i = 1; i <= n + 1; i++) 
		if (s[i] != t[i]) 
		{
			check = false; 
		}
	if (check)
	{
		cout << 0; 
		return 0; 
	}
	for (int i = 1; i <= n + 1; i++)
	{
		if (s[i] != t[i] || i == n + 1)
		{
			if (i != n + 1) 
			{
				ans++; 
			}
			if (par[s[i]] == -1) 
			{
				par[s[i]] = s[i]; 
			}
			if (par[t[i]] == -1) 
			{
				par[t[i]] = t[i]; 
			}
			if (i != n + 1) 
			{
				solve2(s[i],t[i]); 
			}
		}
	}
	for (auto &it : par) 
	{
		if (solve1(it.first) == it.first) 
		{
			ans++; 
		}
	}
	cout << ans - 1; 
}
