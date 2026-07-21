/*
题意：给定n个数，每次可以使得ai和ai+1变成相反数，求能使得n个数的和最大，并求出最大值。

思路：记录负数的个数，如果是偶数，则可以全部化为正数，如果为奇数，这选择绝对值最小的一个，最后sum-=2*minn;
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
	long long n,tmp,summ=0,k=0,minn=1000000009;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>tmp;
		if(tmp<0){
			k++;
			tmp=-tmp;
		}
		summ+=tmp;
		if(minn>tmp)	minn=tmp;
	}
	if(k%2==0)	cout<<summ;
	else		cout<<summ-2*minn;
}
