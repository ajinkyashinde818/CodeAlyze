#include <bits/stdc++.h>
using namespace std;
int main()
{
	int R,G,B,N;
	cin>>R>>G>>B>>N;
	int nb = 0;
	for (int i = 0 ; i <= N ; i++)
	{
		for (int j = 0 ; j <= N ; j++)
		{
			int reste = N - (R * i) - (G * j);
			if (reste >= 0 && reste % B == 0)
			{
				nb++;
			}
		}
	}
	cout<<nb<<endl;
}
