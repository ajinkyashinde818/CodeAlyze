#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <random>
#include <queue>

using namespace std;


int main()
{
	int  N;
	cin >> N ;

	vector<pair<int ,int>> As;

	int a;
	for(int ni = 0; ni < N; ni++){
		cin >> a;
		As.push_back(make_pair(abs(a), a));
	} 

	sort(As.rbegin(), As.rend());

	int flag = 1;
	long long sum = 0;
	for(int ni = 0; ni < N-1; ni++){
		if (flag * As[ni].second < 0) {
			flag = -1;
		}
		else {
			flag = 1;
		}
		sum += abs(As[ni].second);
	}

	sum += flag * As[N - 1].second;

	printf("%lld", sum);

	return 0;
}
