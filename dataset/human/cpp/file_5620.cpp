#include<unordered_map>
#include<iostream>
#include<algorithm>
#include<utility>
#include<climits>
#include<fstream>
#include<cstring>
#include<cstdlib>
#include<iomanip>
#include<cstdio>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<cmath>
#include<list>
#include<map>
#include<set>
#define inf 0x7f7f7f
#define p(x) (x)*(x)
#define PI 3.14159265358979
using namespace std;

typedef vector<vector<int> > vtype;
typedef long long ll;

int main()
{
	//ios::sync_with_stdio(false);
	ll n = 0, r = 0;
	cin >> n >> r;
	if(n <= 10)
		cout << r + 100 * (10 - n) << endl; 
	else
		cout << r << endl; 
    return 0;
}
