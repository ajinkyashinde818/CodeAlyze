#include<bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <stack>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
//typedef tree<int, nuint_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> new_data_set; 
#define int long long
#define MOD 1000000007
#define what_is(x) cerr << #x << " is " << x << endl;
#define loop(i,a,n) for(int i=a;i<n;i++)

#define pb emplace_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, szof(x))
#define sortall(x) sort(aint(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef pair<int, int> pt;


int dp[100010][2];
signed main() {
	
	fastio();
	//#define LOCAL_DEFINE
	#ifdef LOCAL_DEFINE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	//https://codeforces.com/contest/1084/problem/D
	// https://codeforces.com/contest/1155/problem/E
	//https://www.spoj.com/problems/MON2012/
	//https://codeforces.com/blog/entry/52726	
	int n;
	cin>>n;	
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];

	}
	dp[0][0]=0;
	dp[0][1]=-1e18;
	for(int i=0;i<n;i++)
	{
		dp[i+1][0]=max(dp[i][0]+arr[i],dp[i][1]-arr[i]);
		dp[i+1][1]=max(dp[i][0]-arr[i],dp[i][1]+arr[i]);
		//cout<<dp[i+1][0]<<" "<<dp[i+1][1]<<endl;
	}
	cout<<dp[n][0];
	return  0;


}
