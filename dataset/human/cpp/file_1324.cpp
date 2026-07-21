#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long int ll;

#define EPS (1e-7)
#define INF (1e10)
#define PI (acos(-1))

int R, G, B, N;

int ans = 0;
int ans2 = 0;

int main()
{
	cin >> R >> G >> B >> N;

	for (int i = 0; i <= 3000; i++)
	{
		for (int j = 0; j <= 3000; j++)
		{
//			for (int k = 0; k <= (N - i - j) / B; k++)
			{
				
				//if (i * R + j * G + k * B == N) ans++;
			}

//			cout << (N - (i * R + j * G)) << endl;
			if (i * R + j * G > N) continue;
			if ((N - (i * R + j * G)) % B == 0) ans2++;
//			ans2 += (N - (i * R + j * G)) % B;

		}
	}

	cout << endl;

	cout << ans2 << endl;
}
