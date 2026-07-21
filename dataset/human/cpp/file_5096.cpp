/*A - Beginner*/

#include <bits/stdc++.h>
using namespace std;

int main(){


	int contest;
	int score;
	int ans;

	cin >> contest >> score;

	if(contest >= 10)
		cout << score;
	else{
		ans = 100 * (10 - contest);
		ans += score;
		cout << ans;
	}

	return 0;
}
