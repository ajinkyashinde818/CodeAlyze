#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
using namespace std;
const long long N = 1e9 + 7;
typedef long long ll;
map <char,int> ma;
int main()
{
	int n, r;
	cin >> n >> r;
	if(n >= 10)
        cout << r << endl;
    else
        cout << r + 100 * (10 - n) << endl;
	return 0;
}
