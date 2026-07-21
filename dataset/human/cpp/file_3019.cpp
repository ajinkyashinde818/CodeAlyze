#include<iostream>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<cstdio>
#include<cassert>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<string>
#include<deque>
#include<queue>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<iomanip>
#include<utility>
#include<functional>
using namespace std;
int n;
long long a[100005];
long long ans;
int f;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]<0)
		{
			f++;
			a[i]=-a[i];
		}
		ans+=a[i];
	}
	sort(a,a+n);
	if(f%2==1)
		ans-=2*a[0];
	cout<<ans;
	return 0;
}
