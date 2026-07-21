#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
using namespace std;
typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k; cin >> n >> k;
	if (n >= 10) {
		cout << k << '\n';
	}
	else {
		cout << k + (100 * (10 - n)) << '\n';
	}





}
