#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;

const int maxN = 1e5 + 10; 
int a[maxN];
int b[10*maxN];
int c[10*maxN];
vector<int> w[maxN];
int n;
int main()
{
	scanf("%d",&n);
	for(int i=2;i<=1000;i++)
	{
		int k = (i)*(i-1)/2;
		b[k] = 1;
		c[k] = i;
	}
	if(b[n] != 1)
	{
		puts("No");
		return 0;
	}
	else
	{
		puts("Yes");
		printf("%d\n",c[n]);
		int cnt = 0;
		for(int i=1;i<c[n];i++)
		{
			for(int j=i+1;j<=c[n];j++)
			{
				cnt++;
				w[i].push_back(cnt);
				w[j].push_back(cnt);
			}
		}
		for(int i=1;i<=c[n];i++)
		{
			int sz = w[i].size();
			printf("%d ",sz);
			for(int j=0;j<w[i].size()-1;j++)
			{
				printf("%d ",w[i][j]);
			}
			printf("%d\n",w[i][sz-1]);
		}
	}
    return 0;
}
