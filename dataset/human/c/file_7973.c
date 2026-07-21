#include<stdio.h>
#define N 1000000
const int MOD=(int)1e9+7; //which is prime
int x,y;
int min(int a,int b){
	return a<b?a:b;
}
long long fac(int n){
	long long f=1;
	while(n>0){
		f*=n--;
		f%=MOD;
	}
	return f;
}
long long calc(long long x,long long cnt){
	long long ans=1;
	while(cnt>0){
		if((cnt%2)!=0){
			ans*=x;
			ans%=MOD;
		}
		x*=x;
		x%=MOD;
		cnt/=2;
	}
	return ans;
}
long long solve(){
	if((2*x-y)%3||y>2*x||x>2*y)
		return 0;
	int a=(2*x-y)/3,b=(-x+2*y)/3;
	int n=a+b,r=min(a,b);
	long long x1,x2,x3;
	x1=fac(n);
	x2=fac(r)*fac(n-r);
	x2%=MOD;
	x3=calc(x2,MOD-2);
	long long ans;
	ans=x1*x3;
	ans%=MOD;
	return ans;
}
int main(){
	scanf("%d%d",&x,&y);
	printf("%lld",solve());
}
