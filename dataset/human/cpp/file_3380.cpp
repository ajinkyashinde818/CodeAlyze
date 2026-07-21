#include<cstdio>
#include<cstdlib>
#include<cstring>
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

using namespace std;
typedef long long ll;
typedef pair<int,int>P;

int main()
{
	int N,mc=0;
	ll res=0,mn;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		ll t=0;
		cin>>t;
		if(t<0)mc++;
		mn=i==0?t:min(abs(mn),abs(t));
		res+=abs(t);
	}
	if(mc%2)
	{
		res-=mn*2;
	}
	cout<<res<<endl;

}
