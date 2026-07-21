#include <iostream>
#include <vector>

using namespace std;

long long ans = 1;
vector<int> charas(26,0);

int main() {
	int N;
	string str;

	cin >> N >>str;

	for (int i = 0; i < N; i++) {
		charas[str[i] - 'a']++; 
	}

	//文字iを選ぶor選ばない

	for (int i = 0; i < 26; i++) {
		ans =( ans * (charas[i] + 1) )% ((int)1e9 + 7);
	}
	if(ans != 0) ans--;
	else ans = ((int)1e9 + 7) - 1;
	
	cout << ans << endl;

	return 0;
}
