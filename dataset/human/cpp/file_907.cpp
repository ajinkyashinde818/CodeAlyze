#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char c=getchar();int t=0,f=1;
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){t=(t<<3)+(t<<1)+(c^48);c=getchar();}
	return t*f;
}
int n,r,g,b;
int main(){
	r=read();
	g=read();
	b=read();
	n=read();
	int ans=0;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(i*r+j*g>n)continue;
			int k=n-i*r-j*g;
			if(k%b)continue;
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
