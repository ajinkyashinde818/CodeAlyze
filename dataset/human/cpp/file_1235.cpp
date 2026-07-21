#include <bits/stdc++.h>
using namespace std;

int main()
{
	int R, G, B, N;
	int ans = 0;
	cin >> R >> G >> B >> N;
	for (int i = 0; i <= N / R; i++)
		for (int j = 0; j <= (N - R * i) / G; j++)
			if ((N - (R * i + G * j)) % B == 0)
				ans++;
	cout << ans << endl;
}
