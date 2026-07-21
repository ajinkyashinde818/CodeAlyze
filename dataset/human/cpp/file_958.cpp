#include<bits/stdc++.h>
using namespace std;
int main()
{
	int red,green,blue;
	int ways=0;
	int N;
	cin>>red>>green>>blue>>N;
	for(int i=0;i<=N;i+=red)
	{
		for(int j=0;j<=N;j+=green)
		{
			if((N-i-j)%blue==0&&(N-i-j)/blue>=0)
			{
				ways++;
			}
		}
	}
	cout<<ways;
	return 0;
}
