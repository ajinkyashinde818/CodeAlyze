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
	int N;
	cin>>N;
	vector<int> A(N);
	int signcount = 0;
	for(int i=0; i<N; i++)
	{
		cin>>A[i];
		if(A[i]<0)
		{
			signcount++;
		}
		A[i] = abs(A[i]);
	}
	sort(A.begin(),A.end());
	long long result = 0;

	if(signcount % 2 == 0)
	{
		for(int i=0; i<N; i++)
		{
			result += A[i];
		}
	}
	else
	{
		result -= A[0];
		for(int i=1; i<N; i++)
		{
			result += A[i];
		}
	}
	cout<<result<<endl;
	return 0;
}
