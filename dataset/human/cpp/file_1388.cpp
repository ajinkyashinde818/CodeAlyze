#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <string>
#include <numeric>
#include <math.h>
#include <set>
#include <map>
#include <fstream>
#include <complex>
using namespace std;

int main()
{
	int R,G,B,N;
	cin>>R>>G>>B>>N;
	int cnt = 0;
	for(int i=0; R*i<=N; i++)
	{
		for(int j=0; R*i+B*j<=N; j++)
		{
			int remain = N-(R*i+B*j);
			if(remain%G == 0)
			{
				cnt++;
			}
		}
	}
	cout<<cnt<<endl;

	return 0;
}
