#include <map>
#include <set>
#include <ctime>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring> 
#include <iostream>
#include <algorithm>
using namespace std;

int N, R;

int main()
{
	scanf("%d%d", &N, &R);
	if(N < 10)
		printf("%d\n", R + 100 * (10 - N));
	else
		printf("%d\n", R);

	return 0;
}
