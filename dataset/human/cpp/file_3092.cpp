#include<iostream>
#include<limits.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int min_abs = INT_MAX;
	long sum=0;
	int tmp = 0;
	int to_reverse = 0;
	for(int i=0; i<n; i++){
		cin >> tmp;
		sum += abs(tmp);
		if(tmp < 0) to_reverse++;
		if(abs(tmp)<min_abs) min_abs=abs(tmp);
	}
	if(to_reverse%2 == 1) sum -= 2*min_abs;
	cout << sum << endl;

	return 0;
}
