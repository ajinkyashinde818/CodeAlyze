#include <cstdio>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <set>
#include <map>
#include <iostream>
#pragma warning(disable:4996)
using namespace std;


int main()
{
	int N, R;
	cin >> N >> R;
	if (N < 10)R += 100 * (10 - N);
	cout << R;
}
