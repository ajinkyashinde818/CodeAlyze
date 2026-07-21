#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<list>
using namespace std;


int main()
{
	long long output = 0;
	int R, B, G, N;
	cin >> R >> B >> G >> N;
	for (int r = 0; r*R <= N; r++)
	{
		for (int g = 0; r*R + g*G <= N; g++)
		{
			int b = (N - r*R - g*G) / B;
			if (r*R + g*G + b*B == N)
			{
				output++;
			}

		}
	}

	cout << output << endl;

}
