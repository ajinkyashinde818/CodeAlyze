#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstdlib>
#include<bitset>
#include<utility>
using namespace std;


int main(void) {
	int r,g,b,n,ans,tmp,num=0;
	cin>>r>>g>>b>>n;

	for (int ir = 0; ir <= n; ir++) {
		for (int ig = 0; ig <= n; ig++) {
			tmp=ir*r+ig*g;
			if((n-tmp)%b==0&&(n-tmp)/b>=0&&(n-tmp)/b<=n)num++;
		}
	}

	cout<<num<<"\n";

	return 0;
}
