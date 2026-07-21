#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <assert.h>
#include <fstream>

using namespace std;

const long long MOD = 1000000007;

int n;
int cnt[26];

long long ans;

string s;

int main()
{
	cin >> n >> s;
	for (int i = 0;i < n;i++)
		cnt[s[i] - 'a']++;
	ans = 1;
	for (int i = 0;i < 26;i++)
		(ans *= cnt[i] + 1) %= MOD;
	cout << (ans + MOD - 1) % MOD << endl;
	return 0;
}
