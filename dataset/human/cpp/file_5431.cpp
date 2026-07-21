#include <iostream>
#include <algorithm>
#include <deque>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
int main() {
	int a,b,c;
	cin >> a >> b;
	if (a >= 10 ) {
		
		cout << b << endl;
	}
else {
		c = b+100*(10-a);
		cout << c << endl;
}
	return 0;
}
