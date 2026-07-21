#include <iostream>
using namespace std;
int ans[500][500];
int main()
{
	int n,k=1;
	scanf("%d",&n);
	while (k*(k-1)/2<n)
	k++;
	if (k*(k-1)/2==n)
	{
		printf("Yes\n%d\n",k);
		int cur=1;
		for (int i=0;i<k-1;i++)
		{
			for (int j=i;j<k-1;j++)
			ans[i][j]=cur+j-i;
			for (int j=i+1;j<k;j++)
			ans[j][i]=cur+j-i-1;
			cur+=k-i-1;
		}
		for (int i=0;i<k;i++)
		{
			printf("%d",k-1);
			for (int j=0;j<k-1;j++)
			printf(" %d",ans[i][j]);
			printf("\n");
		}
	}
	else
	printf("No");
}
