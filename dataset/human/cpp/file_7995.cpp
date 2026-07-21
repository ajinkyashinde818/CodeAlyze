#include<iostream>
#include<climits>
#include<math.h>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<stdio.h>
#include <string>
#include <complex>
#include <functional>
using namespace std;
//typedef pair<string,string> P;
//double dat[100][100];
//int dp[6][1010];//動的計画法
//int prime[10000001];
//char str[1010][1010];
//vector<pair<int,int> > pc[100001];
//int ABS(int a){return max(a,-a);}
//long long num[100000];
int main(){
	int n;
	cin>>n;
	long long a[n],sum=0;
	for(int i=0;i<n;i++) {
		cin>>a[i];
		sum+=a[i];
	}
	long long x=0,ans=1000000000000000000LL;
	for(int i=0;i<n;i++){
		x+=a[i];
		if(i+1<n) ans=min(ans,abs(sum-2*x));
	}
	cout<<ans<<endl;
	return 0;
}
