#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <functional>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <iomanip>
#if __cplusplus >= 201103L
#include <unordered_map>
#include <unordered_set>
#endif
#define ls x<<1
#define rs x<<1|1
#define fi first
#define se second
#define ll long long
#define pb push_back
#define mp make_pair
#define fun function
#define vi vector<int>
#define lowbit(x) x&(-x)
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);

using namespace std;

const int INF = 0x3f3f3f3f;


int main() {
	IOS;
#ifdef xiaofan
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif

	int a,b;
	cin>>a>>b;
	if(a<10)
		b=b+100*(10-a);
	cout<<b<<endl; 




	return 0;
}
