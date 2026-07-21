#include<iostream>
using namespace std;
typedef long long ll;

int r,g,b,N;
ll ans;

int main() { 
	cin >> r>>g>>b>>N;

	ans = 0;
	for (int i = 0; i*r <= N; i++) {
		for (int j = 0; j*g <= N - i * r; j++) {
			if ((N - (i*r + j * g)) % b == 0) {
				ans++;
			}
		}
	}


	cout << ans << endl;
	return 0;
}
