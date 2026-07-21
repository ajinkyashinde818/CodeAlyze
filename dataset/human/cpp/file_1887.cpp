#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<string.h>

using namespace std;

typedef pair<int,int> pii;

#define rep(i,j) for(int i=0;i<(j);i++)
#define reps(i,j,k) for(int i=j;i<=k;i++)


int main(){
	int q,n,a;
	double d;
	char s[9],b[32];
	scanf("%d",&q);
	rep(i,q){
		scanf("%s",s);
		n=a=0;
		d=0;
		rep(j,8){
			n = n << 4;
			if(s[j]>='0'&& s[j]<='9')n+=(s[j]-'0');
			else n+=(s[j]-'a'+10);
		}
		rep(j,7){
			int p = (n & (1 << j));
			d += p!=0;
			d/=2.0;
		}
		for(int j=30;j>6;j--){
			a*=2;
			if(n & (1<<j))a+=1;
		}
		printf("%s%d.",(n&(1<<31)?"-":""),a);
		do{
			d *= 10;
			int t=floor(d);
			printf("%d",t);
			d-=t;
		}while(d!=0);
		puts("");
	}
	return 0;
}
