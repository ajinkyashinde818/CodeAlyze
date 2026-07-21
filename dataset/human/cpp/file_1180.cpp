#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	int R, G, B, N;
	cin >> R >> G >> B >> N;
	int ans = 0;
    
	int r = N / R;
	int g = N / G;
	int b = N / B;

	for (int i = 0; i <= r; i++)
	{
		for (int j = 0; j <= g; j++)
		{
			if ((N - (R * i + G * j)) % B == 0 && N - (R * i + G * j) >= 0)ans++;
		}
	}
	cout << ans;
}
