#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <stdio.h>
#include <vector>
#include <time.h>
#include <iomanip>
#include <thread>
#include <atomic>
#include <mutex>
#include <future>
#define double long double
#define int long long
#define low lower_bound
#define upp upper_bound
#define mod (int)1e9+7
#define inf (int)1e16
#define rep(i,n) for (int i = 0; i < n; i++)
#define Rep(i,n) for (int i = n; i >= 0; i--)
#define all(vec) vec.begin(),vec.end()
#define vsort(vec) sort(all(vec))
#define vrever(vec) reverse(all(vec));
#define vunsort(vec) vsort(vec); vrever(vec);
#define bisea binary_search
#define cend cout<<endl;
#define P pair<int, int>
#define prique priority_queue<P, vector<P>, greater<P>>
struct edge { int to, cost; };
using namespace std;

signed main() {
	int r, g, b, n;
	cin >> r >> g >> b >> n;
	int cnt = 0;
	rep(i, n + 1) {
		rep(j, n - i + 1) {
			int sum = r * i + g * j;
			if (n - sum < 0) continue;
			if ((n - sum) % b == 0) {
				cnt++;
				
			}
		}
	}
	cout << cnt << endl;
}
