using namespace std;

#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <utility>
#include <functional>
#include <queue>
#include <cmath>
using namespace std;


int main(void){
	long long int N;

	cin >> N;
	auto a = sqrt(N*2);
	auto ai = (int)floor(a);

	if (ai * (ai + 1) != N * 2) {
		cout << "No" << endl;
		return 0;
	}
	
	vector<vector<int>> ret(ai+1);

	for (auto& i : ret)
		i.resize(ai);

	int now = 1;

	for (int i = 0; i < ai; i++) {
		for (int j = i; j < ai; j++) {
			ret[i][j] = ret[j+1][i] = now++;
		}
	}

	cout << "Yes" << endl << ai + 1 << endl;
	for (long long int i = 0; i < ai+1; i++) {
		cout << ret[i].size();
		for (auto j : ret[i])
			cout << " " << j;
		cout << endl;
	}
	return 0;
}
