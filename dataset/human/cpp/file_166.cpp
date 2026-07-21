#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read()
{
	int out=0,fh=1;
	char jp=getchar();
	while ((jp>'9'||jp<'0')&&jp!='-')
		jp=getchar();
	if (jp=='-')
		fh=-1,jp=getchar();
	while (jp>='0'&&jp<='9')
		out=out*10+jp-'0',jp=getchar();
	return out*fh;
}
int main()
{
	int R=read(),G=read(),B=read(),n=read();
	int ans=0;
	for(int r=0;r*R<=n;++r)	
		for(int g=0;g*G+r*R<=n;++g)
			if((n-g*G-r*R)%B==0)
				++ans;
	cout<<ans<<endl;
	return 0;
}
