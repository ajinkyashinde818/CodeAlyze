#include<string>
#include<iostream>
#include<algorithm>
#include<set>
#include<unordered_set>
#include<math.h>
#include<vector>
#include<sstream>
#include<queue>
#include<functional>
#include<bitset>
#include<cstdio>
#include<iomanip>
#include<stack>
#include <cstring>
#include <climits>
using namespace std;
#define rep(i,n) for(int (i)=0;(i) < (n); (i)++)
#define rrep(f,i,n) for(int (i)=0;(i) < (f); (i)++)
#define FIND(v, k) find((v).begin(), (v).end(), k)
#define mset(a,x) memset(a,x,sizeof(a))

#define MAX 101
#define MAX_V 15
long long a[200005];
long long b[200005];
int main()
{
	long long n, s = 0;
	cin >> n;
	rep(i, n) {
		cin >> b[i];
		if (i)
			a[i] = a[i - 1] + b[i];
		else
			a[i] = b[i];
	}
	long long m = a[n - 1] /2;
	long long r = a[0];
	int j=0;
	for (int i = 1; i < n - 1; i++) {
		if (abs(m - a[i]) <= abs(m - r)) {
			r = a[i];
			j = i;
		}
	}
	for (int i = j + 1; i < n; i++) {
		s += b[i];
	}
	cout << abs(s - r) << endl;
}
