#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<queue>

using namespace std;

using ll=long long;
using vi=vector<int>;
using vvi=vector<vi>;
using pii=pair<int,int>;
using vll=vector<ll>;
using vvll=vector<vll>;
using vpii=vector<pii>;

#define PI 3.1415926535897932384626433832795

int main(void)
{
	int n, r;
	while(scanf("%d%d", &n, &r)==2)
	{
		int ans=r;

		if(n<10) ans=r+1000-100*n;
		printf("%d\n", ans);
	}
	return 0;
}
