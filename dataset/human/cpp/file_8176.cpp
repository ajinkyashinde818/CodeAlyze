#include <cstdio>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <set>
#include <bitset>
#include <map>
#define INF 0x3f3f3f3f3f3f3fLL
#define ULL unsigned long long
#define LL long long
#define N 100100
#define eps 10e-9
#define MOD 100000000
#define mem(a,n) memset(a,n,sizeof(a))
#define fread freopen("in.txt","r",stdin)
#define fwrite freopen("out.txt","w",stdout)
using namespace std;
const double PI=acos(-1.0);
LL num[N*2];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	LL sum=0,sumtil=0,ans=INF;
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>num[i];
		sum+=num[i];
	}
	for(int i=0;i<n-1;++i){
		sumtil+=num[i];
		ans=min(ans,abs(sum-2*sumtil));
		//cout<<abs(sum-2*sumtil)<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
