#include<cstdio>
#include<cstring>
#include<algorithm>
int n,a[200010];
long long sum1[200010],sum2[200010],ans=1e18;
template<class T>
inline void read(T&a){
	char c=getchar();
	for(a=0;(c<'0'||c>'9')&&c!='-';c=getchar());
	bool f=0;
	if(c=='-')f=1,c=getchar();
	for(;c>='0'&&c<='9';c=getchar())a=a*10+c-'0';
	if(f)a=-a;
}
int main(){
	read(n);
	for(int i=1;i<=n;i++)read(a[i]),sum1[i]=sum1[i-1]+a[i];
	for(int i=n;i;i--)sum2[i]=sum2[i+1]+a[i];
	for(int i=1;i<n;i++)
		if(std::abs(sum1[i]-sum2[i+1])<ans)ans=std::abs(sum1[i]-sum2[i+1]);
	printf("%lld\n",ans);return 0;
}
