#include <iostream>
#include <string>
#include <stdio.h>
#include <queue>
#include <stack>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <map>
#include <set>
#include <vector>
#include <bits/stdc++.h>
#define debug(a) cout<<" ++ "<<a<<" ++ "<<endl;
using namespace std;
const int maxn = 1000005;

int main()
{
	int dp[3005];
	int r,g,b,n;
	cin>>r>>g>>b>>n;
	int ans = 0;
	for(int i=0;i<=(n/r);i++)
	{
		for(int j=0;j<=(n/g);j++)
		{
			int val = i * r + j * g;
			if( ( (n-val) % b == 0) && ( (n - val)>=0 ))
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
