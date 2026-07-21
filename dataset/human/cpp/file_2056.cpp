#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

long process(const vector<long> &A, int st, int ed, int mul, vector<vector<long>> &memo) {
	if (st == ed-1) {
		return max(A[st]*mul+A[ed], -A[st]*mul-A[ed]);
	}
	if (memo[st][mul+1] != -1)
		return memo[st][mul+1];
	long cand1 = A[st]*mul+ process(A,st+1,ed,1,memo);
	long cand2 = -A[st]*mul + process(A,st+1,ed,-1,memo);
	memo[st][mul+1] = max(cand1,cand2);
	return memo[st][mul+1];
}

int main() {
	int total_n;
	int i;
	
	cin >> total_n;
	vector<long> A(total_n);
	vector<vector<long>> memo(total_n, vector<long>(3,-1));
	for (i=0; i<total_n; i++) {
		cin >> A[i];
	}
	
	cout << process(A,0,A.size()-1,1,memo) << endl;
	return 0;
}
