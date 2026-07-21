#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<map>
#include<iomanip>
#include<sstream>
#include<vector>
#include<stack>
#include<math.h>

using namespace std;


int main()
{
	long long int n, m, a[2000000],r,g,b,res=0;
	cin >> r>>g>>b>>n;
	for (int i = 0; i <= 3000; i++) {
		for (int j = 0; j <= 3000; j++) {
			if ((n - r * i - g * j) % b == 0&& (n - r * i - g * j)>=0) {
				res++;
			}
		}
	}
	cout << res;
}
