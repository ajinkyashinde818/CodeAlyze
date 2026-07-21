#include <stdio.h>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <queue>
#include <cstring>
using namespace std;

int main() {
	int N, R;
	cin >> N >> R;
	if (N > 10)cout << R << endl;
	else cout << R+100 * (10 - N) << endl;
	

}
