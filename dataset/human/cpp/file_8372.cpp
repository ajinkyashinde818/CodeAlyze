#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<vector<pair<int, int> > > vvp;
typedef vector<pair<int,int> > vp;
typedef vector<vector<int> > vvi;
typedef vector<int> vi;
typedef vector<vector<bool> > vvb;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef pair<string, int> psi;
typedef pair<int, int> pii;
#define rep(i,s,n) for(int i = (s); i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define yn(f) (f?"yes":"no")
#define YN(f) (f?"YES":"NO")
#define Yn(f) (f?"Yes":"No")
#define mod 1000000007
#define intmax 2147483647
#define intmin -2147483648
#define longmax 9223372036854775807
#define longmin -9223372036854775808
#define nil -1
int main() {
	int n, m;
	cin >> n >> m;
	vs A(n);
	vs B(m);
	rep(i, 0, n)cin >> A[i];
	rep(i, 0, m)cin >> B[i];
	int d = n - m;
	bool f;
	for (int i = 0; i < d+1; i++)
	{
		for (int j = 0; j < d+1; j++)
		{
			f = true;
			for (int k = 0; k < m; k++)
			{
				string w = A[k + j].substr(i,m);
				if (w != B[k])f = false;
			}
			if (f)break;
		}
		if (f)break;
	}
	cout << Yn(f) << endl;
}
