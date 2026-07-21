#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <tuple>
#include <map>
#include <ctime>
#include <cstdlib>
#include <random>
using namespace std;

int main(){
	int n, r;
	cin >> n >> r;
	if(n >= 10)cout << r << endl;
	else cout << r + 100*(10 - n) << endl;
	return 0;
}
