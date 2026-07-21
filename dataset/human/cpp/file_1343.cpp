#include<cstdio>
#include<cstdlib>
#include<string>
#include<cmath>
#include<cstdlib>
#include<climits>
#include<iostream>
#include<sstream>
#include<utility>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
#include<stack>
#include<functional>
#include<ios>
#include<iomanip>
//#include <boost/multiprecision/cpp_int.hpp>

//namespace mp = boost::multiprecision;
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
//using Bint = mp::cpp_int;


int main()
{
	int R,G,B,N;
	ll res=0;
	cin>>R>>G>>B>>N;
	vector<int>TR;
	for(int i=0;i*R<=N;i++)TR.push_back(N-(i*R));
	for(int i=0;i<TR.size();i++)
	{
		for(int g=0;TR[i]>=g*G;g++)
		{
			if((TR[i]-g*G)%B==0)res++;
		}
	}
	cout<<res<<endl;
}
