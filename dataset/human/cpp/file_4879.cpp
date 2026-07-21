#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
typedef long long ll;

int main () {
ios_base::sync_with_stdio(false);
cin.tie(NULL);

ll n,r;

cin >> n >> r;

if (n<10)
	cout << r+(100*(10-n));
else
	cout << r;


return 0;
}
