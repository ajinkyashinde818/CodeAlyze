#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

int a[MAXN], b[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<=n; ++i) scanf("%d",&b[i]);
	
	static int freqa[MAXN], freqb[MAXN];
	for(int i=1; i<=n; ++i)
		++freqa[a[i]],
		++freqb[b[i]];
	for(int i=1; i<=n; ++i)
		if(freqa[i] + freqb[i] > n)
		{
			printf("No\n");
			return 0;
		}
	
	reverse(b+1,b+n+1);
	vector<int> same;
	int val = -1;
	for(int i=1; i<=n; ++i)
		if(a[i] == b[i])
			val = a[i],
			same.push_back(i);
	
	if(val != -1)
	{
		for(int i=1; i<=n && !same.empty(); ++i)
			if(a[i] != val && b[i] != val)
				swap(b[i], b[same.back()]),
				same.pop_back();
	}
	
	printf("Yes\n");
	for(int i=1; i<=n; ++i)
		printf("%d ",b[i]);
	return 0;
}
