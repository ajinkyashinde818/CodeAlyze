#include<bits/stdc++.h>
using namespace std;

int main() {
	int ti = clock();
	int R, G, B, N; cin >> R >> G >> B >> N;
	long long res = 0;
	for (int r = 0; r * R <= N; r++)
	{
		for (int g = 0; r * R + g * G <= N; g++)
		{
			if((N - r * R - g * G) % B == 0) res++;
		}
	}
	cout << res << endl;
//	cout << (double)(clock() - ti) / CLOCKS_PER_SEC << endl;;
	return 0;
}
