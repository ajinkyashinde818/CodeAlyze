#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(){
	int N;
	cin >> N;
	vector<long> A(N);
	long miNum=0;
	long minNum = LONG_MAX;
	for(int i = 0; i < N; i++){
		cin >> A[i];
		if(A[i] < 0)	miNum++;
		if(minNum > abs(A[i]))
			minNum = abs(A[i]);
	}

	long sum = 0;
	for(int i = 0; i < N; i++){
		sum += abs(A[i]);
	}

	if(miNum%2)
		sum = sum - 2*minNum;

	cout << sum << endl;
}
