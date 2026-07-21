#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
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
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
int N;
vector<ll>A,S;
int main()
{
	cin>>N;
	for(int i=0;i<N;i++)
	{
		ll a;
		cin>>a;
		A.push_back(a);
		if(i==0)S.push_back(a);
		else S.push_back(S[i-1]+a);
	}
	ll r=abs(S[0]-(S[N-1]-S[0]));

	for(int i=0;i<N-1;i++)
	{
		r=min(r,abs(S[i]-(S[N-1]-S[i])));
	}
	cout<<r<<endl;
}
