#include<bits/stdc++.h>
using namespace std;
int main()
{
	int R,G,B,N,ans = 0;
	cin>>R>>G>>B>>N;
	for (int i = 0;i * R <= N; ++i)
		for (int j = 0;j * G <= N; ++j)
		{
			int t = i * R + j * G;
			if (t <= N &&(N - t) % B == 0)
				++ans;
		}
	cout<<ans;
			
}
