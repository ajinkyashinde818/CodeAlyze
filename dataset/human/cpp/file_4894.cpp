#include <bits/stdc++.h>
using namespace std;
//mt19937 mrand(chrono::high_resolution_clock::now().time_since_epoch().count());
//int rnd(int x) { return mrand()%x;}
typedef long long ll;
ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
int main(){
	int n,r;
	scanf("%d%d",&n,&r);
	if(n>=10){
		printf("%d\n",r);
	}
	else{
		printf("%d\n",r+100*(10-n));
	}
	return 0;
}
