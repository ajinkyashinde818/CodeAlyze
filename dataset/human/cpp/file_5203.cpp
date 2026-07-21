#include <iostream>
#include <bitset>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	long long n,r;
	cin >> n >> r;

	if(n >= 10)
		cout << r << endl;
	else
		cout << r +(100*(10-n)) << endl;

	
}
