#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <iterator>
#include <cmath>
#include <set>
#include <deque> 
#include <string>


using namespace std;

int n, r;

int main()
{
	scanf("%d%d", &n, &r);
	
	
	int ans = 0;
	if (n >= 10)
		ans = r;
	else
		ans = r + 100 * (10 - n);
		
	printf("%d\n", ans);
	
	return 0;
}
