#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <functional>

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int main()
{
	int R,G,B,N;
	scanf("%d %d %d %d",&R,&G,&B,&N);
	int ret=0;
	for(int r=0;r*R<=N;r++)
	{
		for(int g=0;g*G<=N;g++)
		{
			if(r*R+g*G<=N&&(N-r*R-g*G)%B==0)
			{
				ret++;
			}
		}
	}
	printf("%d\n",ret);
	return 0;
}
