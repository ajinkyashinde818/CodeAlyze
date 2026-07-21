#include<iostream>
#include<math.h>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<stdlib.h>
#include <set>
#include<iomanip>
#include<map>
#include<unordered_map>
#include<fstream>
#include<stdio.h>
typedef long long ll;
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

#define PI  3.141592
//----------------------------------------
int main(void)
{

	int n, r;

	cin >> n >> r;

	if (n > 10)
	{
		cout << r << endl;
		return 0;
	}

	cout << r + 100 * (10 - n) << endl;

}
