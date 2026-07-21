#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cout << setiosflags(ios::fixed) << setprecision(10);
	int t, d, ta, tb, da, db;
	cin >> t >> d >> ta >> tb >> da >> db;
	double answer = 1e100;
	for(int i = 0; i * da <= d; ++i){
		for(int j = 0; i * da + j * db <= d; ++j){
			if(i == 0 && j == 0){ continue; }
			const double a = i * da * ta, b = j * db * tb;
			const double y = (a + b) / (i * da + j * db);
			answer = min(answer, abs(y - t));
		}
	}
	cout << answer << endl;
	return 0;
}
