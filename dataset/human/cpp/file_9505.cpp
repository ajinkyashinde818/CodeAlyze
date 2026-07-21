#include <set>
#include <map>
#include <queue>
#include <stack>
#include <math.h>
#include <vector>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string.h>
#include <limits.h>
#include <algorithm>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <bits/stdc++.h>

#define ff first
#define ss second
#define ll long long
#define pb push_back
#define mp make_pair
#define inf 1000000007
#define mod 1000000007
#define pii pair <int, int>
#define all(x) x.begin(), x.end()
#define FOR(i, x, y) for (int i = x; i <= y; i++)
//#define tr(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)

//using namespace __gnu_pbds;

using namespace std;

//template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int n, m;

char A[55][55];
char B[55][55];

bool good(int a, int b)
{
	for (int i = a; i < a+m; i++)
		for (int h = b; h < b+m; h++)
			if (A[i][h]!=B[i-a+1][h-b+1])
				return 0;
	return 1;
}

int main()
{
	cin >> n >> m;
	
	FOR (i, 1, n)
		FOR (h, 1, n)
			cin >> A[i][h];
	
	FOR (i, 1, m)
		FOR (h, 1, m)
			cin >> B[i][h];
	
	FOR (i, 1, n)
		FOR (h, 1, n)
			if (i+m-1 <= n && h+m-1 <= n && good(i, h)) {
				cout << "Yes";
				return 0;
			}
	cout << "No";
}
