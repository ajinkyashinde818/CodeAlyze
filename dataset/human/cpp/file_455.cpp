#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main(){
	int a,b,c,d,ans=0;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	for(int i=0;i<=d;++i){
		if(i*a>d) break;
		for(int j=0;j<=d;++j){
			if(i*a+j*b>d) break;
			if((d-i*a-j*b)%c==0) ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
