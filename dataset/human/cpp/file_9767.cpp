#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <cfloat>
#include <ctime>
#include <complex>
#include <cassert>
#include <array>
#include <bitset> 
#include <unordered_map>
#include <random>

using namespace std;
typedef long long LL;
typedef pair<int,int> P;

LL cnt[128];
const LL M=1e9+7;
int main() {
	int N;
	string S;
	cin >> N>>S;
	for(auto c:S)
	{
		cnt[(int)c]++;
	}
	LL ret=1;
	for(int i='a';i<='z';i++)
	{
		ret*=cnt[i]+1;
		ret%=M;
	}
	cout << (ret+M-1)%M << endl;

	return 0;
}
