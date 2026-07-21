#include<iostream>
#include<cstdio>
using namespace std;
int x,n;
int f[10000];
int main(){
	f[0]=1;
	for(register int i=1;i<=3;i++){
		scanf("%d",&x);
		for(register int j=0;j<=5000;j++){
			if(f[j])f[j+x]+=f[j];
		}
	}
	scanf("%d",&n);
	printf("%d\n",f[n]);
	return 0;
}
