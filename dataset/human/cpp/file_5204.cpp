#include <iostream>
#include <cmath>
#include <string>
#include <deque>
using namespace std;

int main(){
	long long N, R;
	cin >> N >> R;
	while (cin){
		if (N < 10) R = R + 100*(10-N);
		cout << R << "\n";
		cin >> N >> R;
	}
	return 0;
}
