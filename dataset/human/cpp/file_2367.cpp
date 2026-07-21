#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <utility>
#include <string.h>
#include <map>
#include <stack>
#include <iomanip>
#include <chrono>
#include <random>
#include <bitset>
#include <math.h>
#include <time.h>
#include <assert.h>
#define rnd mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define ll long long
#define pb push_back 
#define mp make_pair
#define ff first
#define ss second
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(x) x.begin(),x.end() 
#define PII pair <int,int>
#define N 300005
#define MOD 1000000007
#define INF 1000000000000000000
using namespace std;

int A[N];
int main()
{
	int n, cnt = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> A[i];
		if(A[i] < 0)
		{
			A[i] = -A[i];
			cnt++;
		}
	}
	sort(A, A + n);
	ll ans = 0;
	for (int i = 0; i < n; ++i)
	{
		if(i == 0)
		{
			if(cnt & 1)
				ans += -A[i];
			else
				ans += A[i];
		}
		else
		{
			ans += A[i];
		}
	}
	cout << ans;
}
