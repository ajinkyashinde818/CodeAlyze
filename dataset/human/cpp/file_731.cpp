#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <algorithm>
#include <numeric>
#include <utility>
#include <complex>
#include <functional>
#include <climits>

using namespace std;

int main() {
	int r, g, b, n , c = 0;
	cin >> r >> g >> b >> n;
	for (size_t i = 0; r * i <= n; i++)
	{
		for (size_t j = 0; g * j <= n; j++)
		{
			int k = (n - (r * i + g * j));
			if(k >= 0 && k % b == 0) {
				// cout << "ijk" << i << j << (n - (r * i + g * j)) / b << endl;
				c++;
			}
		}
		
	}
	cout << c << endl;
}
