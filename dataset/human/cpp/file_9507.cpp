// acdart
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <string>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <cstdlib>
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define X first
#define Y second
#define F first
#define S second
#define MOD9 1000000009ll
#define MOD7 1000000007ll
#define MOD
#define INF  1023456789ll
#define INF16 10000000000000000ll
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define SZ(x) ((int)(x).size())
#define MAXN 10010
#define MAXM
#define ALL(x) ((x).begin()),((x).end())
#define RESET(a,b) memset(a,b, sizeof a)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
#define LEN(X) strlen(X)
#define FI(a,b,c) for(int a=b; a<c; a++)
#define FD(a,b,c) for(int a=b; a>c; a--)
using namespace std;
typedef long long ll;
typedef long long LL;
typedef double db;
typedef double D;
typedef long double ld;
typedef long double LD;
/*********default*********/

const int maxn = 55;
char a[maxn][maxn], b[maxn][maxn];

int main()
{
	int n, m, ans = 0;
	
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++){
		scanf("%s", a[i]);
	}
	for (int i = 0; i < m; i++){
		scanf("%s", b[i]);
	}
	for (int i = 0; i <= n - m; i++){
		for (int k = 0; k <= n - m; k++){
			int fg = 1;
			for (int j = 0; j < m; j++){
				if (strncmp(b[j], a[i + j] + k, m) != 0){
					fg = 0;
					break;
				}
			}
			if (fg){
				ans = 1;
				break;
			}
		}
		if (ans){
			break;
		}
	}
	puts(ans ? "Yes" : "No");
}
