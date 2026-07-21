/**
 *   created: 03 June 2019  00:25:23
**/
#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int , int> pii;
typedef vector< pair<int , int> > vii;
typedef long long ll;
typedef vector<long long> vl;
typedef pair<long long , long long> pll;
typedef vector< pair<long long , long long> > vll;

#define PB push_back
#define PPB pop_back
#define all(c) c.begin(),c.end()
#define rep(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rrep(i,a,b) for(int i = (int)(a-1); i>=(int)(b); i--)
#define INFLL 2000000000000000007
#define INF 2000000007
#define MOD 1000000007


#define TRACE

#ifdef TRACE
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#else

#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)

#endif


void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

//                                        //AUTHOR: Kaushalesh Shukla

//=========================================================================================================

int main()
{
	optimizeIO();
	int tt=1;
	//cin>>tt;
	while(tt--){
		int num;
		cin>>num;
		vl n,p;
		ll sum=0;
		ll mini = INFLL;
		rep(i,0,num){
			ll x;

			cin>>x;
			if(x<=0)
				n.push_back(x);
			else
				p.push_back(x);
			sum += abs(x);
			mini = min(mini, abs(x));
		}
		if(n.size()%2!=0){
			sum -= 2*mini;
		}
		cout<<sum;
	}
	return 0;
}
