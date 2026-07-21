#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<cstring>
#include <stack>
#include <numeric>
#include<climits>
#include<cmath>
#include<set>
#include<unordered_set>
#include<iomanip>
#include<queue>
#include<unordered_map>
#define vi vector<float>
#define vl vector<long long>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define loop(i,n) for(int i=0; i<n; i++)
#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair<float,float>
#define umap unordered_map<ll,float>
using namespace std;

#define xx first
#define yy second

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

// #ifndef ONLINE_JUDGE
// 	freopen("in.txt", "r", stdin);
// 	freopen("out.txt", "w", stdout);
// #endif

	int n, r;
	cin >> n >> r;

	if (n >= 10) {
		cout << r << endl;
	} else {
		cout << r + 100 * (10 - n) << endl;
	}







	return 0;
}
