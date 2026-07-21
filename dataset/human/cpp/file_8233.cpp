#include <set>          
#include <map>           
#include <list>
#include <ctime>
#include <deque>         
#include <bitset>        
#include <vector>
#include <list>
#include <stack>
#include <random>		 
#include <string>       
#include <numeric>      //  needed for  accumulate
#include <utility>      // needed for std:: move
#include <iterator> 
#include <iostream>   
#include <algorithm> 
#include <functional>    
#include <cmath>         
#pragma warning(disable:4996) // ignore this
#define ve vector
#define pb push_back
#define mp make_pair                     
#define srt(x) sort(x.begin(),x.end())         
#define mod static_cast<long long> (1e9+7)     
#define sumx(x) accumulate(x.begin(),x.end(),0LL)
#define pi 3.14159265358979323846
#define testing 0
using namespace std;
template<typename T>
istream& operator >> (istream& in, ve<T> &v)
{
	for (auto &x : v)
		in >> x;
	return in;
}
template<typename T>
ostream& operator<<(ostream& in, ve<T> &v)
{
	for (auto &x : v)
		in << x << " ";
	return in;
}
long long fast(long long a, long long b, long long mid)
{
	if (b == 0)
		return 1;
	a %= mid;
	long long ans = 1;
	while (b)
	{
		if (b & 1)
		{
			ans = (ans*a) % mid;
		}
		a *= a;
		a %= mid;
		b >>= 1;
	}
	return ans;
}
class solve
{
	int n;
public:
	solve()
	{
		cin >> n;
		ve<int> v(n);
		cin >> v;
		long long sum=sumx(v)-v[0];
		long long sum2=v[0];
		long long ans=abs(sum-sum2);
		for(int i=1;i<n-1;i++)
		{
			sum2+=v[i];
			sum-=v[i];
			ans=min(abs(sum-sum2),ans);
		}
		cout << ans; 
		return;
	}
};
 
int32_t main()
{
	int t = 1, i = 1;
//	scanf("%d", &t);
	while (t--)
	{
		new solve;
	}
	return 0;
}
