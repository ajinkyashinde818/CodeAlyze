#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<vector>
using namespace std;
vector<int>p[100010];
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int main()
{
    int n=read(),k=ceil(sqrt(2*n));
    if(k*(k-1)!=2*n)printf("No\n");
    else
    {
    	printf("Yes\n");
    	printf("%d\n",k);
    	int now=0;
    	for(int i=1;i<k;i++)
    	{
    		for(int j=i+1;j<=k;j++){now++;p[i].push_back(now),p[j].push_back(now);}
    	}
    	for(int i=1;i<=k;i++)
		{
			printf("%d ",k-1);
			for(int j=0;j<k-1;j++)printf("%d ",p[i][j]);
			printf("\n");
		}
    }
	return 0;
}
