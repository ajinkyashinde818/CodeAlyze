#include<stdio.h>
#include<math.h>
#include<queue>
#include<stack>
#include<string.h>
#include<algorithm>
#include<cctype>
#include<vector>
#include<map>
#include<set>
typedef long long ll;
using namespace std;
const ll mod=1e9+7;
int main()
{
	int n,r;
	scanf("%d%d",&n,&r);
	if(n>=10)printf("%d\n",r);
	else printf("%d\n",r+100*(10-n));
}
