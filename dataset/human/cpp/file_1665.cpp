#include<cstdio>
#include<cmath>
#include<vector>


using namespace std;
using vi=vector<int>;
using vvi=vector<vi>;


void vi_rot(vi&a)
{
	a.push_back(a.front());
	a.erase(a.begin());
}


int main(void)
{
	int n;

	while(scanf("%d", &n)==1)
	{
		int a=int(-1+sqrt(1.001+8.0*n))/2;
		int b=n*2/a;
		vvi ans(b);
		int last=0;

		if(a*a+a!=2*n)
		{
			printf("No\n");
			continue;
		}

		printf("Yes\n%d\n", b);
		for(int i=0;i<b;i++)
		{
			for(;ans[i].size()<a-i;)
			{
				ans[i].push_back(++last);
			}
			for(int j=0;j<i;j++)
			{
				ans[i].push_back(ans[j].front());
				vi_rot(ans[j]);
			}
		}
		for(auto&ma:ans)
		{
			printf("%d %d", a, ma[0]);
			for(int i=1;i<a;i++) printf(" %d", ma[i]);
			printf("\n");
		}
	}

	return 0;
}
