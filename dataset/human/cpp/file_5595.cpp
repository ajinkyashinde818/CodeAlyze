#include <cstdio>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
using namespace std;
int main()
{
	int n, r;
	cin >> n >> r;
	if(n>=10) 
	{
		cout << r;
	}
	else
	{
		cout << r+100*(10-n);
	}
	

	return 0;
}
