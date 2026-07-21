#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>
#include<math.h>
#include<stack>
#include<set>
#include<map>
#include<complex>
#include<fstream>
#define INF 2e9
#define rep(i,n,m) for(int i=n;i<m;i++)

using namespace std;

//
int main()
{
	int n, r;
	cin >> n >> r;
	if (n >= 10)cout << r << endl;
	else cout << r + 100 * (10 - n) << endl;
}
