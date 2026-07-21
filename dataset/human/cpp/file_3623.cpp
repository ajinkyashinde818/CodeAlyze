#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int N;
	int A[100000];
	cin >> N;

	int counter = 0;
	long long sum = 0;
	int min = 1e9;
	for (int i = 0; i < N; i++){
		cin >> A[i];
		if(A[i] < 0){
			counter++;
		}
		int temp = abs(A[i]);
		sum += temp;
		if(temp < min){
			min = temp;
		}
	}

	if(counter % 2 == 1){
		cout << sum - 2 * min << endl;
	} else {
		cout << sum << endl;
	}

	return 0;
}
