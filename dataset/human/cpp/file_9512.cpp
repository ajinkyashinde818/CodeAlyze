#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#define s(n)                        scanf("%d",&n)
#define sc(n)                       scanf("%c",&n)
#define sl(n)                       scanf("%I64d",&n)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)
#define INF                         (int)1e9
#define EPS                         1e-9
#define bitcount                    __builtin_popcount
#define gcd                         __gcd
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define foreach(v, c)               for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define all(a)                      a.begin(), a.end()
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          push_back
#define fill(a,v)                    memset(a, v, sizeof a)
#define sz(a)                       ((int)(a.size()))
#define mp                          make_pair
#define MOD                         1000000007
typedef long long ll;
/*For you see , each day i love you
 more.Today more than yesterday
  less than tomorrow.*/
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	
	vector<string> a,b;
	
	for(int i = 0;i<n;i++)
	{
		string str;cin>>str;
		a.push_back(str);
	}
	
	for(int i = 0;i<m;i++)
	{
		string str;cin>>str;
		b.push_back(str);
	}
	
	if(m > n)
	{
		cout<<"No"<<endl;
	}
	else
	{
		bool ans = false;
		
		for(int i = 0;i<=n-m;i++)
		{
			for(int j = 0;j<=n-m;j++)
			{
			//	cout<<i<<" "<<j<<endl;
				
				bool is = true;
				for(int l = 0;l<m;l++)
				{
					for(int x = 0;x<m;x++)
					{
						if(a[i+l][j+x] != b[l][x]) is = false;
					}
				}
				
				ans|=is;	
			}
		}
		
		if(ans) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
		
	}
	return 0;
}
