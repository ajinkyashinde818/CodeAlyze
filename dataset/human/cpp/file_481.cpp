#include<bits/stdc++.h>
using namespace std;
int i,i0,n,m;
int main()
{
    int a,b,c,ans=0;
	scanf("%d %d %d %d",&a,&b,&c,&n);
	for(i=0;i*a<=n;i++)for(i0=0;a*i+b*i0<=n;i0++)ans+=((n-a*i-b*i0)%c==0);
    printf("%d\n",ans);
    return 0;
}
