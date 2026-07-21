#include <bits/stdc++.h>
using namespace std;

int main(){
	int R, G, B, N;
	cin >> R >> G >> B >> N;

	int ans = 0;
	int maxr = N / R;
	for (int r = 0; r <= maxr; r++)
	{
		int maxg = (N - R * r) / G;
		for (int g = 0; g <= maxg; g++)
		{
			if( (N - R * r - G * g) % B == 0 )
			{
				ans++;
			}
		}
	}
	cout << ans << endl;
	
	return 0;
}
