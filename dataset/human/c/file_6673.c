#include<stdio.h>

#define max(p,q)((p)>(q)?(p):(q))

int M=-1e9,ans=-1e9;

void f(){
	int t;
	if(~scanf("%d",&t)){
		f();
		ans=max(ans,M-t);
		M=max(M,t);
	}
}

int main(){
	scanf("%*d");
	f();
	printf("%d\n",ans);
}
