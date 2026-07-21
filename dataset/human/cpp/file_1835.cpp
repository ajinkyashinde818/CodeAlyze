#include <iostream>
#include <vector>
#include <map>

using std::cin;
using std::cout;
using std::endl;

int main(void) {
	std::map<int,int> seq;
	int n,m;
	cin >> n >> m;
	for (int i = 1; i < n+1; i++) {
		seq[i] = i;
	}

	int now = 0;
	int num;
	for (int i = 0; i < m; i++) {
		cin >> num;
		seq[now] = num;
		now--;
	}

	std::vector<bool> check(n+1,false);
	int count = 0;
	for (int i = now+1; i < n+1 && count != n; i++) {
		num = seq[i];
		if ( !check[num] ) {
			cout << num << endl;
			count++;
			check[num] = true;
		}
	}

	return 0;
}
