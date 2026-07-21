#include <bits/stdc++.h>
using namespace std;

long long DP[100007][2];
int neg,n;
long long arr[100005],sum,mini;

long long f(int x, int y){
	if(x>=n){
		if(y==1)return -arr[x];
		else return arr[x];
	}
	
	if(DP[x][y]!=-1000000000000000LL) return DP[x][y];
	
	if(y==1){
		return DP[x][y] = max(arr[x]*(-1LL)+f(x+1,0),arr[x]+f(x+1,1));
	} else{
		return DP[x][y] = max(arr[x]+f(x+1,0),arr[x]*(-1LL)+f(x+1,1));
	}
}



int main(){
	scanf("%d",&n);
	mini = 1000000000;
	for(int i =1;i<=n;i++){
		scanf("%lld",&arr[i]);
//		sum+=abs(arr[i]);
//		mini = min(abs(arr[i]),mini);
//		if(arr[i]<0) neg++;
	}
	for(int i =0;i<=100005;i++){
		DP[i][0] = DP[i][1] = -1000000000000000LL;
	}
	long long ans = f(1,0);

	printf("%lld\n",ans);

	return 0;
}
