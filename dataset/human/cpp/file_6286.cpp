#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <stack>

using namespace std;

#define long long long
#define fi first
#define se second
typedef pair<int,int> ii;

const long MOD = 1e9+7;


int main()
{
	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("input.in", "r", stdin);

	long hit = 0;
	int n; cin >> n;
	string s; cin >> s;

	long res = 1;
	{
		long fac = 1;
		for(long i = 1; i <= n; i++) fac = (fac*i)%MOD;
		long hit = 0;

		for(int i = 0; i < 2*n; i++)
		{
			if(hit&1)
			{
				// cout << "A\n";
				if(s[i] == 'W')
					hit++;
				
				if(s[i] == 'B')
				{
					if(hit)
					{
						res = (1LL*res*hit)%MOD;
						hit--;
					}
					else
					{
						cout << "0\n";
						return 0;
					}
				}
			}
			else 
			{
				// cout << "B\n";
				if(s[i] == 'B')
					hit++;
				if(s[i] == 'W')
				{
					if(hit)
					{
						res = (1LL*res*hit)%MOD;
						hit--;
					}
					else
					{
						cout << "0\n";
						return 0;
					}
				}
			}
			// cout << hit << " " << s[i] << "\n";
		}
		if(hit == 0)
			cout << (res*fac)%MOD << "\n";
		else cout << "0\n";
	}
}
