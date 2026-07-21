#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int r, g, b, n;
	cin >> r >> g >> b >> n;
	int answer = 0;
	for(int i = 0; i * r <= n; ++i){
		for(int j = 0; j * g + i * r <= n; ++j){
			if((n - i * r - j * g) % b == 0){ ++answer; }
		}
	}
	cout << answer << endl;
	return 0;
}
