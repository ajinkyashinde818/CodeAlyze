#include<iostream>
#include<ctype.h>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long Abs(long long x){
	return x<0?-x:x;
}
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(!isdigit(ch))f|=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+(ch^48),ch=getchar();
	return f?-x:x;
}
long long a,sum[200007],ans=999999999999999ll;
int main(){
    int n=read();
    for(int i=1;i<=n;++i)a=read(),sum[i]=sum[i-1]+a;
    for(int i=1;i<n;++i)ans=min(ans,Abs(sum[n]-sum[i]-sum[i]));
    cout<<ans<<"\n";
    return 0;
}
