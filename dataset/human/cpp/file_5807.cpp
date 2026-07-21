#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <cassert>
 
#pragma comment(linker, "/STACK:336777216")  
 
using namespace std;

const int MAXN = 1000000 + 10;

int N;
long long L;
int Trie[MAXN][2], End[MAXN], nTrie;
char S[MAXN];

void InsertTrie(char* S)
{
	int p = 0;
	for (int i = 0; S[i]; i ++)
	{
		if (Trie[p][S[i] - '0'] == -1)
			Trie[p][S[i] - '0'] = nTrie ++;
		p = Trie[p][S[i] - '0'];
	}
	End[p] = 1;
}

long long DFS(int i, int Dep)
{
	if (Trie[i][0] == -1 && Trie[i][1] == -1)
		return 0;
	
	long long ans = 0;

	for (int c = 0; c < 2; c ++)
	{
		if (Trie[i][c] != -1)
			ans ^= DFS(Trie[i][c], Dep + 1);
		else
		{
			long long tmp = L - Dep;
			tmp = (tmp & -tmp);
			ans ^= tmp;
		}
	}
	return ans;
}

int dp[100];

int mex(set <int> v)
{
	for (int x = 0; ; x ++)
		if (v.find(x) == v.end())
			return x;
}

void Work()
{
	/*
	dp[1] = 1;
	for (int i = 2; i < 100; i ++)
	{
		set <int> s;
		int p = 0;
		s.insert(p);
		for (int j = i - 1; j >= 1; j --)
		{
			p ^= dp[j];
			s.insert(p);
		}
		dp[i] = mex(s);

	}
	*/


	scanf("%d%lld", &N, &L);
	
	memset(Trie, -1, sizeof(Trie));
	nTrie = 1;
	for (int i = 0; i < N; i ++)
	{
		scanf("%s", S);
		InsertTrie(S);
	}

	printf(DFS(0, 0) ? "Alice\n" : "Bob\n");
}
 
int main()
{
	Work();
	return 0;
}
