#include <bits/stdc++.h>
const int N=100005;
typedef long long ll;
int n,a[N];
using namespace std;

vector<int> V[N];
int main()
{
	//freopen ("code.in","r",stdin);
	//freopen ("code.out","w",stdout);
	scanf ("%d",&n);
	int i,j,k;
	for (k=2;k*(k-1)/2<=n;k++)
	if (k*(k-1)/2==n) break;
	if (k*(k-1)/2==n) puts("Yes");
	else{puts("No");return 0;}
	if (n==1){printf ("2\n1 1\n1 1\n");return 0;}
	printf ("%d\n",k);
	int now=1;
	for (i=1;i<=k;i++)
	for (j=i+1;j<=k;j++)
	V[i].push_back(now),V[j].push_back(now),now++;
	for (i=1;i<=k;i++)
	{
		printf ("%d ",V[i].size());
		for (j=V[i].size()-1;j>=0;j--)
		printf ("%d ",V[i][j]);
		printf ("\n");
	}
	return 0;
}
