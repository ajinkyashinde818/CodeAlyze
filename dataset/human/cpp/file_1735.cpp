#include<cstdio>
#include<cmath>
#include<vector>
std::vector<int>a[1010];
int n;
int main()
{
	scanf("%d",&n);
	int k=((int)(sqrt(1+8*n))+1)/2;
	if(k*(k-1)/2!=n){
		printf("No\n"); return 0;
	}
	int tot=0;
	for(int i=1;i<=k;i++)
		for(int j=1;j<i;j++){
			++tot;
			a[i].push_back(tot); a[j].push_back(tot);
		}
	printf("Yes\n");
	printf("%d\n",k);
	for(int i=1;i<=k;i++){
		int size=a[i].size();
		printf("%d ",size);
		for(int j=0;j<size;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
}
